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
#include "util.hpp"
#include "item.hpp"
#include "button.hpp"
#include "label.hpp"
#include "chg_value.hpp"

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
class Frame {
public:
	Frame();
	void Init(void);
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
