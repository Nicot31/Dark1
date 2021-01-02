/**
 ******************************************************************************
 * File Name   : button.cpp
 * Description :
 *
 * Created on  : 2 janv. 2021
 *     Author  : Thierry
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/
#include <string.h>
#include "button.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/

/* Methods ------------------------------------------------------------------*/
Button::Button(Point p, int width, int height, int backClr, int borderClr,
		int borderSz, const char *txt, int textClr, LcdFont ft) {

	rect = Rectangle(p, width, height);
	backColor = backClr;
	borderColor = borderClr;
	borderSize = borderSz;
	textColor = textClr;
	label = (char *)txt;
	font = ft;
}

/*---------------------------------------------------------------------------*/
void Button::SetColor(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		backColor = back;
	if (border != COLOR_NONE)
		borderColor = border;
	if (text != COLOR_NONE)
		textColor = text;
}

/*---------------------------------------------------------------------------*/
void Button::Draw() {
	lcd.FillRect(rect, backColor);
	lcd.Rect(rect, borderColor);
	for (int i=1; i<borderSize; i++) {
		lcd.Rect(rect.p1.x+i, rect.p1.y+i, rect.p2.x-i, rect.p2.y-i, borderColor);
	}
	if (strlen(label) > 0) {
		lcd.SetFontColor(textColor);
		lcd.SetBackColor(backColor);
		lcd.SetFont(font);
		lcd.TextPutsCenterRect(rect, label);
	}
}

/*---------------------------------------------------------------------------*/

