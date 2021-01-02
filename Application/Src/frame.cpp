 /**
  ******************************************************************************
  * File Name   : frame.cpp
  * Description : 
  *
  * Created on  : 2 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


/* Includes -----------------------------------------------------------------*/
# include "frame.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/
Frame frame = Frame();

/* Methods ------------------------------------------------------------------*/


/* Methods ------------------------------------------------------------------*/
Frame::Frame() {
	nbItems = 0;
}

void Frame::SetDefaultColor(int backClr, int borderClr, int textClr) {
backColor = backClr;
borderColor = borderClr;
textColor = textClr;
}

/*---------------------------------------------------------------------------*/
void Frame::SetDefaultBorderSize(int size) {
borderSize = size;
}

/*---------------------------------------------------------------------------*/
void Frame::SetDefaultTextFont(LcdFont ft){
font = ft;
}

/*---------------------------------------------------------------------------*/
void Frame::Add(Item *item) {
	items.push_back(item);
	nbItems++;
}

/*---------------------------------------------------------------------------*/
void Frame::Draw() {
	for (auto it = items.begin(); it != items.end(); ++it) {
		(*it)->Draw();
	}
}


