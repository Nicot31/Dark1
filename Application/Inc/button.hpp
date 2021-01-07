/**
 ******************************************************************************
 * File Name   : button.hpp
 * Description : Push button that can be clicked
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
	Button(int id, Point p, int width, int height, const char *txt = "");

	static void SetDefaultColor(int back, int border, int text); 		// Default color for all instances. COLOR_NONE to keep unchanged
	static void SetDefaultColorActif(int back, int border, int text); 	// Default color for all instances. COLOR_NONE to keep unchanged
	static void SetDefaultFont(LcdFont ft);								// Default font for all instances.
	static void SetDefaultBorderSize(int size);							// Default border size in pixels for all instances

	void SetColor(int back, int border, int text); 		// The button colors, COLOR_NONE to keep unchanged
	void SetColorActif(int back, int border, int text); // The button color when pushed, COLOR_NONE to keep unchanged
	void SetFont(LcdFont font);							// The text font
	void SetText(const char *txt);						// Change the text

	void SetAction(void (*CallBack)(int event, int id));

	bool Event(int evt, Point& pos);					// pos is relative to button coordinates. Return true if event is processed

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
	const char *text;
	LcdFont font;

private:
	void (*pCallBack)(int event, int id);
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
