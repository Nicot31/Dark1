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
	Button(int id, Point p, int width, int height, const char *label = "");

	static void SetDefaultColor(int back, int border, int text); 		// COLOR_NONE to keep unchanged
	static void SetDefaultColorActif(int back, int border, int text); 	// COLOR_NONE to keep unchanged
	static void SetDefaultFont(LcdFont ft);
	static void SetDefaultBorderSize(int size);

	void SetColor(int back, int border, int text); 		// COLOR_NONE to keep unchanged
	void SetColorActif(int back, int border, int text); // COLOR_NONE to keep unchanged
	void SetFont(LcdFont font);

	bool Event(int evt, Point& pos);					// pos is relative to button. Return true if event is processed

private:
	void Draw(void);

public:
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

private:
	static int defaultBackColor;
	static int defaultBorderColor;
	static int defaultTextColor;
	static int defaultBackColorActif;
	static int defaultBorderColorActif;
	static int defaultTextColorActif;
	static int defaultBorderSize;
	static LcdFont defaultFont;

};

#endif /* INC_BUTTON_HPP_ */
