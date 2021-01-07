 /**
  ******************************************************************************
  * File Name   : chg_value.cpp
  * Description : 
  *
  * Created on  : 7 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


/* Includes -----------------------------------------------------------------*/
#include <string>
#include "chg_value.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/
int ChgValue::defaultBackColor = COLOR_BLACK;
int ChgValue::defaultBackColorActif = COLOR_GRAY2;
int ChgValue::defaultBorderColor = COLOR_GRAY;
int ChgValue::defaultTextColor = COLOR_WHITE;
int ChgValue::defaultBorderSize = 2;
LcdFont ChgValue::defaultFont = LcdFont(0, 0, 0);		// will be initialized in Frame constructor

/* Methods ------------------------------------------------------------------*/
ChgValue::ChgValue(int id, Point p, int width, int height) : Item() {
	ID = id;
	rect = Rectangle(p, width, height);
	btnLeft  = new Button(id+1000, p, height, height, "<");
	btnRight = new Button(id+2000, p.Shift(width-height, 0), height, height, ">");
	text = new Label(-1, p.Shift(height, 0), width - 2*height, height, "");
	text->SetIndent(INDENT_CENTER);
	SetColors(defaultBackColor, defaultBackColorActif, defaultBorderColor, defaultTextColor);
	SetBorderSize(defaultBorderSize);
	SetFont(defaultFont);
}


/*---------------------------------------------------------------------------*/
void ChgValue::SetDefaultColors(int back, int backActif, int border, int text) {
	defaultBackColor = back;
	defaultBackColorActif = backActif;
	defaultBorderColor = border;
	defaultTextColor = text;
}


void ChgValue::SetDefaultBorderSize(int size) {
	defaultBorderSize = size;
}


void ChgValue::SetDefaultFont(LcdFont font) {
	defaultFont = font;
}

/*---------------------------------------------------------------------------*/
void ChgValue::SetColors(int back, int backActif, int border, int textColor) {
	btnLeft->SetColors(back, border, textColor);
	btnRight->SetColors(back, border, textColor);
	btnLeft->SetColorsActif(backActif, -1, -1);
	btnRight->SetColorsActif(backActif, -1, -1);
	text->SetColors(back, border, textColor);
}

void ChgValue::SetBorderSize(int size) {
	btnLeft->SetBorderSize(size);
	btnRight->SetBorderSize(size);
	text->SetBorderSize(size);
}

void ChgValue::SetFont(LcdFont font) {
	btnLeft->SetFont(font);
	btnRight->SetFont(font);
	text->SetFont(font);
}

/*---------------------------------------------------------------------------*/
void ChgValue::SetRange(int mi, int ma, int st) {
	min = mi;
	max = ma;
	if (max > 99999) {
		max = 99999;
	}
	if (max < min) {
		max = min;
	}
	step = st;
}

/*---------------------------------------------------------------------------*/
void ChgValue::SetValue(int val) {
	char sBuf[6];
	if (val < min) {
		val = min;
	} else if (val > max) {
		val = max;
	}
	value = val;
	sprintf(sBuf, "%d", value);
	text->SetText(sBuf);
}

/*---------------------------------------------------------------------------*/
void ChgValue::Draw() {
	btnLeft->Draw();
	text->Draw();
	btnRight->Draw();
}


/*---------------------------------------------------------------------------*/
bool ChgValue::Event(int evt, Point& pos) {

	// if button disabled, the event is not managed
	if (fEnable == false)
		return false;

	// check left button
	if (pos.x <= rect.height) {
		btnLeft->Event(evt, pos);
		if (evt == EVT_PEN_DOWN) {
			SetValue(value - step);
			text->Draw();
		}
		return true;
	} else if (pos.x >= rect.width - rect.height) {
		btnRight->Event(evt, pos);
		if (evt == EVT_PEN_DOWN) {
			SetValue(value + step);
			text->Draw();
		}
		return true;
	}

	return true;
}


