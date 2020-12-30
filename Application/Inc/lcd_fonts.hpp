/**
  ******************************************************************************
  * File Name          : LCD_FONTS.h
  * Description        : This file provides FONTS for the LCD driver
  *
  * These fonts are supported:
  *  - 7 x 10 pixels
  *  - 11 x 18 pixels
  *  - 16 x 26 pixels
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_LCD_FONT_HPP_
#define INC_LCD_FONT_HPP_
#include "stm32f4xx_hal.h"

/* Includes ------------------------------------------------------------------*/

class LcdFont {
public:
	LcdFont(int width, int height, const uint16_t *data);

	int 	width;  	// Font width in pixels
	int 	height;		// Font height in pixels
	const uint16_t  *data; 	// Pointer to data array
};


// Font name definition
extern LcdFont Font_7x10;
extern LcdFont Font_11x18;
extern LcdFont Font_16x26;


#endif /*INC_LCD_FONT_HPP_ */

