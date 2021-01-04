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
#include "item.hpp"

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
class Button: public Item {
public:
	Button(Point p, int width, int height, int backColor, int borderColor,
			int borderSize = 1, const char *label = "", int textColor = COLOR_WHITE,
			LcdFont font = Font_7x10);

	void Draw(void);
	void SetColor(int back, int border, int text); 		// COLOR_NONE to keep unchanged
	void SetColorActif(int back, int border, int text); // COLOR_NONE to keep unchanged
	bool Event(int evt, Point& pos);			// pos is relative to button. Return true if event is processed

	// Attributes
	int backColor;
	int borderColor;
	int textColor;
	int backColorActif;
	int borderColorActif;
	int textColorActif;
	int borderSize;
	char *label;
	LcdFont font;
};

#endif /* INC_BUTTON_HPP_ */
