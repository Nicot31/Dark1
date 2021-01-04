 /**
  ******************************************************************************
  * File Name   : frame.hpp
  * Description : 
  *
  * Created on  : 2 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


#ifndef INC_FRAME_HPP_
#define INC_FRAME_HPP_

#include <vector>
#include "item.hpp"
#include "button.hpp"
#include "util.hpp"

/* Constants -----------------------------------------------------------------*/
#define EVT_PEN_DOWN	1
#define EVT_PEN_UP		2
#define EVT_PEN_MOVE	3

/* Class ---------------------------------------------------------------------*/
class Frame {
public:
	Frame();
	void SetDefaultColor(int backColor, int borderColor, int textColor);
	void SetDefaultBorderSize(int size);
	void SetDefaultTextFont(LcdFont font);
	void Add(Item *item);
	void Draw(void);
	void EventManagement(int event, Point pos);

	// Attributes
	int backColor;
	int borderColor;
	int textColor;
	int borderSize;
	LcdFont font;

private:
	int nbItems;
	std::vector<Item*> items;
	bool capture;
	int currentItem;

};


extern Frame frame;

#endif /* INC_FRAME_HPP_ */