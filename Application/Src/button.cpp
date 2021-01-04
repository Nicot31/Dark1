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
#include "frame.hpp"
#include "button.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/

/* Methods ------------------------------------------------------------------*/
Button::Button(Point p, int width, int height, int backClr, int borderClr,
		int borderSz, const char *txt, int textClr, LcdFont ft) {

	rect = Rectangle(p, width, height);
	backColor = backColorActif = backClr;
	borderColor = borderColorActif = borderClr;
	textColor = textColorActif = textClr;
	borderSize = borderSz;
	label = (char *)txt;
	font = ft;
	fEnable = true;
	fActif = false;
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

void Button::SetColorActif(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		backColorActif = back;
	if (border != COLOR_NONE)
		borderColorActif = border;
	if (text != COLOR_NONE)
		textColorActif = text;
}

/*---------------------------------------------------------------------------*/
void Button::Draw() {
	lcd.FillRect(rect, (fActif) ? backColorActif : backColor);
	for (int i=0; i<borderSize; i++) {
		lcd.Rect(rect.p1.x+i, rect.p1.y+i, rect.p2.x-i, rect.p2.y-i, (fActif) ? borderColorActif : borderColor);
	}
	if (strlen(label) > 0) {
		lcd.SetFontColor((fActif) ? textColorActif : textColor);
		lcd.SetBackColor((fActif) ? backColorActif : backColor);
		lcd.SetFont(font);
		lcd.TextPutsCenterRect(rect, label);
	}
}

/*---------------------------------------------------------------------------*/
bool Button::Event(int evt, Point& pos) {

	// if button disabled, the event is not managed
	if (fEnable == false)
		return false;

	switch (evt) {
	case EVT_PEN_DOWN:
		Activate(true);
		Draw();
		break;
	case EVT_PEN_UP:
		Activate(false);
		Draw();
		break;
	case EVT_PEN_MOVE:
		break;
	}

	return true;
}
