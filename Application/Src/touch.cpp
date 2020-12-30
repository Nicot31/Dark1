/**
 ******************************************************************************
 * File Name          : TOUCH.c
 * Description        : This file provides code for the touch screen
 * 						Touch Screen Driver : XPT2046
 ******************************************************************************
 */
/* Includes -----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include "touch.hpp"
#include "lcd.hpp"

/* Constants ----------------------------------------------------------------*/

#define XPT2046_READ_X 		0xD0
#define XPT2046_READ_Y 		0x90

#define XPT2046_HOR_RES     320
#define XPT2046_VER_RES     240
#define XPT2046_MIN       	200
#define XPT2046_MAX	       	3800

#define SORT(a,b) { if ((a)>(b)) SWAP((a),(b)); }
#define SWAP(a,b) { int temp=(a);(a)=(b);(b)=temp; }

/* Global Variables ---------------------------------------------------------*/
extern SPI_HandleTypeDef hspi2;

TouchScreen touch = TouchScreen();

/* Function ------------------------------------------------------------------*/

int TouchPenInterrupt(void) {
	return (HAL_GPIO_ReadPin(PEN_INT_GPIO_Port, PEN_INT_Pin) == GPIO_PIN_RESET);
}

/* Methods ------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
// Constructor
TouchScreen::TouchScreen() {
	//orientation = LCD_LANDSCAPE_1;
	//width = XPT2046_HOR_RES;
	//height = XPT2046_VER_RES;
}

/*---------------------------------------------------------------------------*/
void TouchScreen::Reset() {
	uint8_t Cmd;
	uint8_t Data;

	// Reset
	Cmd = 0x80;
	HAL_SPI_TransmitReceive(&hspi2, &Cmd, &Data, 1, 1000);
	Cmd = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &Cmd, &Data, 1, 1000);
	Cmd = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &Cmd, &Data, 1, 1000);
	HAL_Delay(5);
}


/*---------------------------------------------------------------------------*/
void TouchScreen::SetOrientation(int w, int h, int o) {

	orientation = o;
	width = w;
	height = h;
}


/*---------------------------------------------------------------------------*/
int TouchScreen::Get(uint8_t address) {
	int val;
	uint8_t Cmd = 0x00;
	uint8_t Data;

	// Reset
	HAL_SPI_TransmitReceive(&hspi2, &address, &Data, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &Cmd, &Data, 1, 1000);
	val = (uint16_t) Data << 8;
	HAL_SPI_TransmitReceive(&hspi2, &Cmd, &Data, 1, 1000);
	val |= Data;
	val >>= 3;
	return val;
}

/*---------------------------------------------------------------------------*/
void TouchScreen::GetXY(int *x, int *y, bool norm) {

	*x = Get(XPT2046_READ_X);
	*y = Get(XPT2046_READ_Y);

	if ((orientation == LCD_LANDSCAPE_1) || (orientation == LCD_LANDSCAPE_2)) {
		SWAP(*x, *y);
	}

	if (norm) {
		if (*x < XPT2046_MIN)
			*x = XPT2046_MIN;
		else if (*x > XPT2046_MAX)
			*x = XPT2046_MAX;
		if (*y < XPT2046_MIN)
			*y = XPT2046_MIN;
		else if (*y > XPT2046_MAX)
			*y = XPT2046_MAX;
	}
}

/*---------------------------------------------------------------------------*/
int TouchScreen::FastMedian(int *samples) {

	// do a fast median selection (reference code available on internet). This code basically
	// avoids sorting the entire samples array

	SORT(samples[0], samples[5]);
	SORT(samples[0], samples[3]);
	SORT(samples[1], samples[6]);
	SORT(samples[2], samples[4]);
	SORT(samples[0], samples[1]);
	SORT(samples[3], samples[5]);
	SORT(samples[2], samples[6]);
	SORT(samples[2], samples[3]);
	SORT(samples[3], samples[6]);
	SORT(samples[4], samples[5]);
	SORT(samples[1], samples[4]);
	SORT(samples[1], samples[3]);
	SORT(samples[3], samples[4]);

	return samples[3];
}

/*---------------------------------------------------------------------------*/
void TouchScreen::Correction(int *x, int *y) {
	*x -= XPT2046_MIN;
	*y -= XPT2046_MIN;

	*x = ((*x) * width) / (XPT2046_MAX - XPT2046_MIN);
	*y = ((*y) * height) / (XPT2046_MAX - XPT2046_MIN);

	switch (orientation) {
		case LCD_PORTRAIT_1:
			*y = height - *y;
			break;
		case LCD_PORTRAIT_2:
			*x = width - *x;
			break;
		case LCD_LANDSCAPE_1:
			*x = width - *x;
			*y = height - *y;
			break;
		case LCD_LANDSCAPE_2:
			break;
		}
}

/*---------------------------------------------------------------------------*/
void TouchScreen::GetXYMedian(int *x, int *y) {
	int i;
	int tab_x[7], tab_y[7];

	for (i = 0; i < 7; i++) {
		GetXY(&tab_x[i], &tab_y[i], true);
	}

	*x = FastMedian(tab_x);
	*y = FastMedian(tab_y);
	Correction(x, y);
}
