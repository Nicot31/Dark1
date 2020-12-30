/**
 ******************************************************************************
 * File Name          : LCD.c
 * Description        : This file provides code for the LCD driver
 * 						TFT LCD Driver : ILI9341
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "main.h"
#include "lcd.hpp"
#include "lcd_fonts.hpp"
#include "touch.hpp"

/* Constants -----------------------------------------------------------------*/
// Address
#define LCD_CMD      (*((volatile uint16_t *) 0x60000000))
#define LCD_PARAM    (*((volatile uint16_t *) 0x60080000))

// Regulative Command Set
#define LCD_NOP                 0x00
#define LCD_RESET				0x01
#define LCD_R_DISP_INFO         0x04
#define LCD_R_DISP_STATUS       0x09
#define LCD_R_DSIP_POWER_MODE   0x0A
#define LCD_R_DISP_MADCTL       0x0B
#define LCD_R_PIXEL_FORMAT      0x0C
#define LCD_R_IMAGE_FORMAT      0x0D
#define LCD_R_DISP_SIGNAL_MODE  0x0E
#define LCD_R_SELF_DIAG_RESULT  0X0F
#define LCD_ENTER_SLEEP_MODE    0x10
#define LCD_SLEEP_OUT			0x11
#define LCD_PARTIAL_MODE_ON     0x12
#define LCD_NORMAL_DISP_ON      0x13
#define LCD_DISP_INVERSION_OFF  0x20
#define LCD_DISP_INVERSION_ON   0x21
#define LCD_GAMMA_SET			0x26
#define LCD_DISP_OFF			0x28
#define LCD_DISP_ON 			0x29
#define LCD_COLUMN_ADDR_SET		0x2A
#define LCD_PAGE_ADDR_SET		0x2B
#define LCD_MEMORY_WRITE        0x2C
#define LCD_COLOR_SET           0x2D
#define LCD_MEMRY_READ          0x2E
#define LCD_PARTIAL_AREA        0x30
#define LCD_VERT_SCROLL_DEF     0x33
#define LCD_TEARING_LINE_OFF    0x34
#define LCD_TEARING_LINE_ON     0x35
#define LCD_MEMORY_ACCESS_CTRL  0x36
#define LCD_VERT_SCROLL_ADR     0x37
#define LCD_IDLE_MODE_OFF       0x38
#define LCD_IDLE_MODE_ON        0x39
#define LCD_PIXEL_FORMAT		0x3A
#define LCD_W_MEM_CONTINUE      0x3C
#define LCD_R_MEM_CONTINUE      0x3E
#define LCD_SET_TEAR_SCANLINE   0x44
#define LCD_GET_SCANLINE        0x45
#define LCD_W_DISP_BRIGHTNESS	0x51
#define LCD_R_DISP_BRIGHTNESS   0x52
#define LCD_W_CTRL_DISP         0x53
#define LCD_R_CTRL_DISP         0x54
#define LCD_W_ADAPT_BRIGHT      0x55
#define LCD_R_ADAPT_BRIGHT      0x56
#define LCD_W_CBAC_MIN_BRIGHT   0x5E
#define LCD_R_CBAC_MIN_BRIGHT   0x5F
#define LCD_R_ID1               0xDA
#define LCD_R_D2                0xDB
#define LCD_R_D3                0xDC

// Extended Command Set
#define LCD_RGB_SIGNAL_CTRL     0xB0
#define LCD_FRAME_CTRL_NORMAL   0xB1
#define LCD_FRAME_CTRL_IDLE     0xB2
#define LCD_FRAME_CTRL_PARTIAL  0xB3
#define LCD_DISP_INV_CTRL       0xB4
#define LCD_BLANK_PORCH_CTRL    0xB5
#define LCD_DISP_FCT_CTRL       0xB6
#define LCD_ENTER_MODE_SET      0xB7
#define LCD_BACKLIGHT_CTRL_1    0xB8
#define LCD_BACKLIGHT_CTRL_2    0xB9
#define LCD_BACKLIGHT_CTRL_3    0xBA
#define LCD_BACKLIGHT_CTRL_4    0xBB
#define LCD_BACKLIGHT_CTRL_5    0xBC
#define LCD_BACKLIGHT_CTRL_6    0xBD
#define LCD_BACKLIGHT_CTRL_7    0xBE
#define LCD_BACKLIGHT_CTRL_8    0xBF
#define LCD_POWER_CTRL_1        0xC0
#define LCD_POWER_CTRL_2        0xC1
#define LCD_VCOM_CTRL_1         0xC5
#define LCD_VCOM_CTRL_2         0xC7
#define LCD_NV_MEM_W            0xD0
#define LCD_NV_MEM_PROT_KEY     0xD1
#define LCD_NV_MEM_STATUS_R     0xD2
#define LCD_R_ID4               0xD3
#define LCD_POS_GAMMA_CORRECT   0xE0
#define LCD_NEG_GAMMA_CORRECT   0xE1
#define LCD_DIGIT_GAMMA_CTRL_1  0xE2
#define LCD_DIGIT_GAMMA_CTRL_2  0xE3
#define LCD_INTERFACE_CTRL      0xF6

#define SWAP(a,b) { int temp=(a);(a)=(b);(b)=temp; }

/* Global Variables ----------------------------------------------------------*/

LcdScreen lcd = LcdScreen();

/* Methods -------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
// Constructor
LcdScreen::LcdScreen(int orientation) {

	fontColor = LCD_COLOR_WHITE;
	backgroundColor = LCD_COLOR_BLACK;
	SetOrientation(orientation);
	SetColors(LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	SetFont(Font_7x10);
}

/*----------------------------------------------------------------------------*/
// Private : Store the orientation for the LCD
void LcdScreen::SetOrientation(int orientation) {

	switch (orientation) {
	case LCD_PORTRAIT_1:
		orientation = LCD_PORTRAIT_1;
		height = LCD_WIDTH;
		width = LCD_HEIGHT;
		break;
	case LCD_PORTRAIT_2:
		orientation = LCD_PORTRAIT_2;
		height = LCD_WIDTH;
		width = LCD_HEIGHT;
		break;
	case LCD_LANDSCAPE_1:
		orientation = LCD_LANDSCAPE_1;
		height = LCD_HEIGHT;
		width = LCD_WIDTH;
		break;
	case LCD_LANDSCAPE_2:
		orientation = LCD_LANDSCAPE_2;
		height = LCD_HEIGHT;
		width = LCD_WIDTH;
		break;
	}
	// set the touch screen orientation
	touch.SetOrientation(width, height, orientation);
}

/*----------------------------------------------------------------------------*/
// Set Text Font and Background colors
void LcdScreen::SetColors(int font, int back) {
	fontColor = font;
	backgroundColor = back;
}

void LcdScreen::SetFontColor(int color) {
	fontColor = color;
}

int LcdScreen::GetFontColor() {
	return fontColor;
}

void LcdScreen::SetBackColor(int color) {
	backgroundColor = color;
}

int LcdScreen::GetBackColor() {
	return backgroundColor;
}

void LcdScreen::SetFont(LcdFont font) {
	fontData = font.data;
	fontWidth = font.width;
	fontHeight = font.height;
}

LcdFont LcdScreen::GetFont(void) {
	LcdFont font = LcdFont(fontWidth, fontHeight, fontData);
	return font;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::Init() {
	LCD_CMD = LCD_RESET;
	HAL_Delay(120);       // wait 500ms

	SleepOff();
	HAL_Delay(120);

	LCD_CMD = LCD_PIXEL_FORMAT;
	LCD_PARAM = 0x55;   // 16bits / pixel

	Orientation(LCD_LANDSCAPE_1);
	SetFont(Font_7x10);

	SetTextArea(0, 0, width, height);
	FillScreen(LCD_COLOR_BLACK);

	DisplayOn();
}

/*----------------------------------------------------------------------------*/
void LcdScreen::Orientation(int orientation) {
	uint16_t Param;

	// Set the attributes
	SetOrientation(orientation);

	switch (orientation) {
	case LCD_PORTRAIT_1:
		Param = 0x88;
		break;
	case LCD_PORTRAIT_2:
		Param = 0x58;
		break;
	case LCD_LANDSCAPE_1:
		Param = 0xE8;
		break;
	case LCD_LANDSCAPE_2:
		Param = 0x28;
		break;
	default:
		return;
	}

	LCD_CMD = LCD_MEMORY_ACCESS_CTRL;
	LCD_PARAM = Param;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::SleepOn() {
	LCD_CMD = LCD_ENTER_SLEEP_MODE;
}

void LcdScreen::SleepOff() {
	LCD_CMD = LCD_SLEEP_OUT;
}

void LcdScreen::DisplayOn() {
	LCD_CMD = LCD_DISP_ON;
}

void LcdScreen::DisplayOff() {
	LCD_CMD = LCD_DISP_OFF;
}

void LcdScreen::IdleModeOn() {
	LCD_CMD = LCD_IDLE_MODE_ON;
}

void LcdScreen::IdleModeOff() {
	LCD_CMD = LCD_IDLE_MODE_OFF;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::Brightness(int val) {
	LCD_CMD = LCD_W_DISP_BRIGHTNESS;
	LCD_PARAM = (uint16_t) val & 0xFF;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::SetCursor(int x, int y) {
	SetFrame(x, y, x, y);
}

/*----------------------------------------------------------------------------*/
void LcdScreen::SetFrame(int x1, int y1, int x2, int y2) {
	LCD_CMD = LCD_COLUMN_ADDR_SET;
	LCD_PARAM = (uint16_t) x1 >> 8;
	LCD_PARAM = (uint16_t) x1 & 0xFF;
	LCD_PARAM = (uint16_t) x2 >> 8;
	LCD_PARAM = (uint16_t) x2 & 0xFF;
	LCD_CMD = LCD_PAGE_ADDR_SET;
	LCD_PARAM = (uint16_t) y1 >> 8;
	LCD_PARAM = (uint16_t) y1 & 0xFF;
	LCD_PARAM = (uint16_t) y2 >> 8;
	LCD_PARAM = (uint16_t) y2 & 0xFF;
}

/*----------------------------------------------------------------------------*/
/*  TEXT																	  */
/*----------------------------------------------------------------------------*/
void LcdScreen::SetTextArea(int x1, int y1, int x2, int y2) {
	txtAreaX1 = x1;
	txtAreaY1 = y1;
	txtAreaX2 = x2;
	txtAreaY2 = y2;
	txtAreaPosX = x1;
	txtAreaPosY = y1;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::SetTextPos(int x, int y) {
	txtAreaPosX = x;
	txtAreaPosY = y;
}

/*----------------------------------------------------------------------------*/
// Draw a char in the screen at the current position with the current font
void LcdScreen::TextPutc(char c) {
	int i, j;
	uint16_t *pData;
	uint16_t Data;

	// Check if printable char
	c = c - 32;
	if ((c < 0) || (c > 94))
		return;

	// Test if we are at the end of the line
	if ((txtAreaPosX + fontWidth) > txtAreaX2) {
		txtAreaPosX = txtAreaX1;
		txtAreaPosY += fontHeight;
	}

	// Set the rectangle frame to draw
	SetFrame(txtAreaPosX, txtAreaPosY, txtAreaPosX + fontWidth - 1,
			txtAreaPosY + fontHeight - 1);

	// Draw char data
	pData = (uint16_t*) fontData + (fontHeight * c);
	LCD_CMD = LCD_MEMORY_WRITE;
	for (i = 0; i < fontHeight; i++) {
		Data = *pData++;
		for (j = 0; j < fontWidth; j++) {
			if (Data & 0x8000) {
				LCD_PARAM = (uint16_t) fontColor;
			} else {
				LCD_PARAM = (uint16_t) backgroundColor;
			}
			Data <<= 1;
		}
	}

	// Update Text Pointer
	txtAreaPosX += fontWidth;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::TextPuts(char *str) {
	while (*str) {
		/* New line */
		if (*str == '\n') {
			txtAreaPosY += fontHeight;
			txtAreaPosX = txtAreaX1;
			str++;
		} else if (*str == '\r') {
			txtAreaPosX = txtAreaX1;
			str++;
		} else {
			TextPutc(*str++);
		}
	}
}

/*----------------------------------------------------------------------------*/
void LcdScreen::TextPutsAt(int x, int y, char *str) {
	SetTextPos(x, y);
	TextPuts(str);
}

/*----------------------------------------------------------------------------*/
void LcdScreen::GetStringSize(char *str, int *width, int *height) {
	*height = fontHeight;
	*width = fontWidth * strlen(str);
}

/*----------------------------------------------------------------------------*/
void LcdScreen::WriteMem(uint16_t *mem, int size) {
	LCD_CMD = LCD_MEMORY_WRITE;
	while (size--) {
		LCD_PARAM = *mem++;
	}
}

/*----------------------------------------------------------------------------*/
/*  DRAW																	  */
/*----------------------------------------------------------------------------*/
void LcdScreen::DrawPixel(int x, int y, int color) {
	SetCursor(x, y);
	LCD_CMD = LCD_MEMORY_WRITE;
	LCD_PARAM = (uint16_t) color;
}

/*----------------------------------------------------------------------------*/
void LcdScreen::DrawLine(int x1, int y1, int x2, int y2, int color) {
	int dx, dy;
	int stepx, stepy;
	int fraction;

	dy = (y2 - y1);
	dx = (x2 - x1);

	if (dy < 0) {
		dy = -dy;
		stepy = -1;
	} else {
		stepy = 1;
	}

	if (dx < 0) {
		dx = -dx;
		stepx = -1;
	} else {
		stepx = 1;
	}

	dx <<= 0x01;
	dy <<= 0x01;

	DrawPixel(x1, y1, color);

	if (dx > dy) {
		fraction = (dy - (dx >> 1));
		while (x1 != x2) {
			if (fraction >= 0) {
				y1 += stepy;
				fraction -= dx;
			}
			x1 += stepx;
			fraction += dy;

			DrawPixel(x1, y1, color);
		}
	} else {
		fraction = (dx - (dy >> 1));

		while (y1 != y2) {
			if (fraction >= 0) {
				x1 += stepx;
				fraction -= dy;
			}
			y1 += stepy;
			fraction += dx;
			DrawPixel(x1, y1, color);
		}
	}
}

/*----------------------------------------------------------------------------*/
void LcdScreen::DrawHLine(int x1, int x2, int y, int color) {
	if (x2 < x1)
		SWAP(x1, x2);
	SetFrame(x1, y, x2, y);
	LCD_CMD = LCD_MEMORY_WRITE;
	while (x2-- >= x1) {
		LCD_PARAM = (uint16_t) color;
	}

}

/*----------------------------------------------------------------------------*/
void LcdScreen::DrawVLine(int x, int y1, int y2, int color) {
	if (y2 < y1)
		SWAP(y1, y2);
	SetFrame(x, y1, x, y2);
	LCD_CMD = LCD_MEMORY_WRITE;
	while (y2-- >= y1) {
		LCD_PARAM = (uint16_t) color;
	}

}

/*----------------------------------------------------------------------------*/
void LcdScreen::Rect(int x1, int y1, int x2, int y2, int color) {
	DrawHLine(x1, x2, y1, color);
	DrawHLine(x1, x2, y2, color);
	DrawVLine(x1, y1, y2, color);
	DrawVLine(x2, y1, y2, color);
}

/*----------------------------------------------------------------------------*/
void LcdScreen::FillRect(int x1, int y1, int x2, int y2, int color) {
	uint32_t size;
	SetFrame(x1, y1, x2, y2);
	size = (x2 - x1) * (y2 - y1);
	LCD_CMD = LCD_MEMORY_WRITE;
	while (size--) {
		LCD_PARAM = (uint16_t) color;
	}
}

/*----------------------------------------------------------------------------*/
void LcdScreen::FillScreen(int color) {
	FillRect(0, 0, width - 1, height - 1, color);
}

/*----------------------------------------------------------------------------*/
void LcdScreen::Circle(int xc, int yc, int radius, bool fill, int color) {
	int a = 0;
	int p = 0x0000;

	p = (1 - radius);

	do {
		if (fill) {
			DrawHLine((xc - a), (xc + a), (yc + radius), color);
			DrawHLine((xc - a), (xc + a), (yc - radius), color);
			DrawHLine((xc - radius), (xc + radius), (yc + a), color);
			DrawHLine((xc - radius), (xc + radius), (yc - a), color);
		} else {
			DrawPixel((xc + a), (yc + radius), color);
			DrawPixel((xc + radius), (yc + a), color);
			DrawPixel((xc - a), (yc + radius), color);
			DrawPixel((xc - radius), (yc + a), color);
			DrawPixel((xc + radius), (yc - a), color);
			DrawPixel((xc + a), (yc - radius), color);
			DrawPixel((xc - a), (yc - radius), color);
			DrawPixel((xc - radius), (yc - a), color);
		}

		if (p < 0) {
			p += (0x03 + (0x02 * a++));
		} else {
			p += (0x05 + (0x02 * ((a++) - (radius--))));
		}
	} while (a <= radius);
}

