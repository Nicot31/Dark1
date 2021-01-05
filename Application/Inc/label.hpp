 /**
  ******************************************************************************
  * File Name   : label.hpp
  * Description : Display text in a box. Can't be selected.
  *
  * Created on  : 5 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


#ifndef INC_LABEL_HPP_
#define INC_LABEL_HPP_

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
#include "util.hpp"
#include "lcd_fonts.hpp"
#include "lcd.hpp"
#include "item.hpp"

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
class Label: public Item {
public:
	Label(int id, Point p, int width, int height, const char *txt = "");

	static void SetDefaultColor(int back, int border, int text); 		// Default color for all instances. COLOR_NONE to keep unchanged
	static void SetDefaultFont(LcdFont ft);								// Default font for all instances.
	static void SetDefaultBorderSize(int size);							// Default border size in pixels for all instances
	static void SetDefaultIndent(int indent);							// Default indentation for all instances

	void SetColor(int back, int border, int text); 		// The button colors, COLOR_NONE to keep unchanged
	void SetFont(LcdFont font);							// The text font
	void SetBorderSize(int size);						// Default border size in pixels for all instances
	void SetIndent(int indent);							// Default indentation for all instances
	void SetText(const char *txt);						// Change the text

	bool Event(int evt, Point& pos);					// pos is relative to button coordinates. Return true if event is processed

private:
	void Draw(void);

public:
	// Attributes
	int backColor;
	int borderColor;
	int textColor;
	int borderSize;
	int indent;
	const char *text;
	LcdFont font;

private:
	static int defaultBackColor;
	static int defaultBorderColor;
	static int defaultTextColor;
	static int defaultBorderSize;
	static int defaultIndent;
	static LcdFont defaultFont;

};





#endif /* INC_LABEL_HPP_ */
