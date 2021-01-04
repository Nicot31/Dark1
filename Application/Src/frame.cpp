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
	capture = false;
	currentItem = -1;
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
	//for (auto it = items.begin(); it != items.end(); ++it) {
	//	(*it)->Draw();
	//}
	for (int i=0; i<nbItems; i++) {
		items[i]->Draw();
	}
}


/*---------------------------------------------------------------------------*/
void Frame::EventManagement(int event, Point pos) {
	bool bEvtManaged;
	Item *elt;

	switch (event) {
	case EVT_PEN_DOWN:
		for (int i=0; i<nbItems; i++) {
			elt = items[i];
			if (elt->rect.IsPointInside(pos)) {
				currentItem = i;
				pos.x -= elt->rect.p1.x;
				pos.y -= elt->rect.p1.y;
				bEvtManaged = elt->Event(event, pos);
				if (bEvtManaged)
					break;
			}
		}
		break;
	case EVT_PEN_UP:
		if (currentItem >= 0) {
			items[currentItem]->Event(event, pos);
			currentItem = -1;
		}
		break;
	case EVT_PEN_MOVE:
		break;

	}
}
