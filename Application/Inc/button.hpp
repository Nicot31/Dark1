/**
 ******************************************************************************
 * File Name   : button.hpp
 * Description :
 *
 * Created on  : 2 janv. 2021
 *     Author  : Thierry
 ******************************************************************************
 */

#ifndef INC_BUTTON_HPP_
#define INC_BUTTON_HPP_

#include "util.hpp"
#include "lcd_fonts.hpp"
#include "lcd.hpp"

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
class Button {
public:
	Button(Point p, int width, int height, int backColor, int borderColor,
			int borderSize = 1, const char *label = "", int txtColor = LCD_COLOR_WHITE,
			LcdFont font = Font_7x10);

	void Draw(void);

	Rectangle rect = Rectangle(0, 0, 0, 0);
	int backColor;
	int borderColor;
	int borderSize;
	int txtColor;
	char *label;
	LcdFont font;
};

#endif /* INC_BUTTON_HPP_ */
