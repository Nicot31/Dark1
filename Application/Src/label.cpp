 /**
  ******************************************************************************
  * File Name   : label.cpp
  * Description : Display text in a box. Can't be selected.
  *
  * Created on  : 5 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


/* Includes -----------------------------------------------------------------*/
#include <string.h>
#include "label.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/
int Label::defaultBackColor = COLOR_BLACK;
int Label::defaultBorderColor = COLOR_GRAY;
int Label::defaultTextColor = COLOR_WHITE;
int Label::defaultBorderSize = 0;
int Label::defaultIndent = INDENT_LEFT;
LcdFont Label::defaultFont = LcdFont(0, 0, 0);		// will be initialized in Frame constructor

/* Methods ------------------------------------------------------------------*/
Label::Label(int id, Point p, int width, int height, const char *txt) : Item() {

	ID = id;
	rect = Rectangle(p, width, height);
	backColor = defaultBackColor;
	borderColor = defaultBorderColor;
	textColor = defaultTextColor;
	borderSize = defaultBorderSize;
	indent = defaultIndent;
	text[0] = 0;
	font = defaultFont;
}

/*---------------------------------------------------------------------------*/
void Label::SetDefaultColors(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		defaultBackColor = back;
	if (border != COLOR_NONE)
		defaultBorderColor = border;
	if (text != COLOR_NONE)
		defaultTextColor = text;
}

void Label::SetDefaultBorderSize(int size) {
	defaultBorderSize = size;
}

void Label::SetDefaultIndent(int ind) {
	defaultIndent = ind;
}
void Label::SetDefaultFont(LcdFont ft) {
	defaultFont = ft;
}

/*---------------------------------------------------------------------------*/
void Label::SetColors(int back, int border, int text) {
	// COLOR_NONE to keep unchanged
	if (back != COLOR_NONE)
		backColor = back;
	if (border != COLOR_NONE)
		borderColor = border;
	if (text != COLOR_NONE)
		textColor = text;
}

void Label::SetFont(LcdFont ft) {
	font = ft;
}

void Label::SetBorderSize(int size) {
	borderSize = size;
}

void Label::SetIndent(int ind) {
	indent = ind;
}

void Label::SetText(const char *txt) {
	strncpy(text, txt, 99);
	text[99] = 0;
}

/*---------------------------------------------------------------------------*/
void Label::Draw() {
	lcd.FillRect(rect, backColor);
	for (int i=0; i<borderSize; i++) {
		lcd.Rect(rect.p1.x+i, rect.p1.y+i, rect.p2.x-i, rect.p2.y-i, borderColor);
	}
	if (strlen(text) > 0) {
		lcd.SetFontColor(textColor);
		lcd.SetBackColor(backColor);
		lcd.SetFont(font);
		switch (indent) {
		case INDENT_LEFT:
			lcd.PrintTextLeftRect(rect, text);
			break;
		case INDENT_CENTER:
			lcd.PrintTextCenterRect(rect, text);
			break;
		case INDENT_RIGHT:
			lcd.PrintTextRightRect(rect, text);
			break;
		}
	}
}

/*---------------------------------------------------------------------------*/
bool Label::Event(int evt, Point& pos) {
	// A Label do not process events
	return true;
}
/*---------------------------------------------------------------------------*/



