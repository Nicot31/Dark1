 /**
  ******************************************************************************
  * File Name   : item.cpp
  * Description : 
  *
  * Created on  : 2 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


/* Includes -----------------------------------------------------------------*/
#include "item.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/

/* Methods ------------------------------------------------------------------*/
Item::Item() {
	fEnable = true;
	fActif = false;
	ID = -1;
}

void Item::Enable(bool fEna) {
	fEnable = fEna;
}

bool Item::IsEnable() {
	return fEnable;
}

void Item::Activate(bool fAct) {
	fActif = fAct;
}

bool Item::IsActif() {
	return fActif;
}

void Item::Draw() {
}

bool Item::Event(int evt, Point& pos) {
	return false;
}




/*---------------------------------------------------------------------------*/



