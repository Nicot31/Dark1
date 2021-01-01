/**
  ******************************************************************************
  * File Name          : LCD.hpp
  * Description        : This file provides code for the LCD driver
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_LCD_HPP_
#define INC_LCD_HPP_

/* Includes ------------------------------------------------------------------*/
#include "lcd_fonts.hpp"

/* Constants -----------------------------------------------------------------*/

// LCD settings
#define LCD_WIDTH               320
#define LCD_HEIGHT              240
#define LCD_PIXEL               76800

// LCD orientation
#define LCD_LANDSCAPE_1			0
#define LCD_LANDSCAPE_2			1
#define LCD_PORTRAIT_1			2
#define LCD_PORTRAIT_2			3

// Colors
#define LCD_COLOR_WHITE			0xFFFF
#define LCD_COLOR_BLACK			0x0000
#define LCD_COLOR_RED           0xF800
#define LCD_COLOR_GREEN			0x07E0
#define LCD_COLOR_GREEN2		0xB723
#define LCD_COLOR_BLUE			0x001F
#define LCD_COLOR_BLUE2			0x051D
#define LCD_COLOR_YELLOW		0xFFE0
#define LCD_COLOR_ORANGE		0xFBE4
#define LCD_COLOR_CYAN			0x07FF
#define LCD_COLOR_MAGENTA		0xA254
#define LCD_COLOR_GRAY			0x7BEF
#define LCD_COLOR_BROWN			0xBBCA

// Transparent background, only for strings and chars
#define LCD_TRANSPARENT			0x80000000


/* Class ---------------------------------------------------------------------*/
class Point {
public:
	Point(int x=0, int y=0);

	int x;
	int y;
};


class LcdScreen {
public:
	LcdScreen(int orientation = LCD_LANDSCAPE_1);

	void SetColors(int fontColor, int backgroundColor);
	void SetFontColor(int fontColor);
	int  GetFontColor(void);
	void SetBackColor(int backgroundColor);
	int  GetBackColor(void);
	void SetFont(LcdFont font);
	LcdFont GetFont(void);
	void SetTextArea(int x1, int y1, int x2, int y2);
	void SetTextPos(int x, int y);
	void GetStringSize(const char* str, int *width, int *hight);

	// Commands
	void Init(void);
	void Orientation(int orientation);
	void SleepOn(void);
	void SleepOff(void);
	void DisplayOn(void);
	void DisplayOff(void);
	void IdleModeOn(void);
	void IdleModeOff(void);
	void Brightness(int val);
	int  ComposeColor(uint8_t red, uint8_t green, uint8_t blue);
	// text
	void TextPutc(char c);
	void TextPuts(const char *str);
	void TextPutsAt(int x, int y, const char *str);
	void TextPutsCenterX(int y, const char *str);
	void TextPutsCenterY(int x, const char *str);
	void TextPutsCenterXY(const char *str);
	// Draw
	void DrawPixel(int x, int y, int color);
	void Line(int x1, int y1, int x2, int y2, int color);
	void HLine(int x1, int x2, int y, int color);
	void VLine(int x, int y1, int y2, int color);
	void Rect(int x1, int y1, int x2, int y2, int color);
	void FillRect(int x1, int y1, int x2, int y2, int color);
	void FillScreen(int color);
	void Circle(int xc, int yc, int radius, int color);
	void FillCircle(int xc, int yc, int radius, int color);

	void Calibrate(void);


private:
	void SetOrientation(int orientation);
	void SetCursor(int x, int y);
	void SetFrame(int x1, int y1, int x2, int y2);
	void WriteMem(uint16_t *mem, int size);
	void DrawCrossHair(Point p, int color);
	bool ReadTestPoint(Point *p);



public:
	// Screen
	int	orientation;
	int width;
	int height;

	// font
	int fontColor;
	int backgroundColor;
	const uint16_t *fontData; // Font information
	int	fontWidth;
	int	fontHeight;

	// text
	int txtAreaX1;		// Text area definition
	int txtAreaY1;
	int txtAreaX2;
	int txtAreaY2;
	int txtAreaPosX;	// Text position
	int txtAreaPosY;
};

/* Variables -----------------------------------------------------------------*/
extern LcdScreen lcd;

#endif /* INC_LCD_HPP_ */
