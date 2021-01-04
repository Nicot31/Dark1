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
int Button::defaultBackColor = COLOR_GRAY;
int Button::defaultBorderColor = COLOR_GRAY2;
int Button::defaultTextColor = COLOR_WHITE;
int Button::defaultBackColorActif = COLOR_GRAY2;
int Button::defaultBorderColorActif = COLOR_GRAY;
int Button::defaultTextColorActif = COLOR_WHITE;
int Button::defaultBorderSize = 2;
LcdFont Button::defaultFont = LcdFont(0, 0, 0);		// will be initialized in Frame constructor

/* Methods ------------------------------------------------------------------*/
Button::Button(int id, Point p, int width, int height, const char *txt) : Item() {

	ID = id;
	rect = Rectangle(p, width, height);
	backColor = defaultBackColor;
	backColorActif = defaultBackColorActif;
	borderColor = defaultBorderColor;
	borderColorActif = defaultBorderColorActif;
	textColor = defaultTextColor;
	textColorActif = defaultTextColorActif;
	borderSize = defaultBorderSize;
	label = (char *)txt;
	font = defaultFont;
}

/*---------------------------------------------------------------------------*/
void Button::SetDefaultColor(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		defaultBackColor = back;
	if (border != COLOR_NONE)
		defaultBorderColor = border;
	if (text != COLOR_NONE)
		defaultTextColor = text;
}

void Button::SetDefaultColorActif(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		defaultBackColorActif = back;
	if (border != COLOR_NONE)
		defaultBorderColorActif = border;
	if (text != COLOR_NONE)
		defaultTextColorActif = text;
}

void Button::SetDefaultBorderSize(int size) {
	defaultBorderSize = size;
}

void Button::SetDefaultFont(LcdFont ft) {
	defaultFont = ft;
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

void Button::SetFont(LcdFont ft) {
	font = ft;
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
