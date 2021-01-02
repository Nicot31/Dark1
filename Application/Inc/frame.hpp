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

/* Constants -----------------------------------------------------------------*/


/* Class ---------------------------------------------------------------------*/
class Frame {
public:
	Frame();
	void SetDefaultColor(int backColor, int borderColor, int textColor);
	void SetDefaultBorderSize(int size);
	void SetDefaultTextFont(LcdFont font);
	void Add(Item *item);
	void Draw(void);

	// Attributes
	int backColor;
	int borderColor;
	int textColor;
	int borderSize;
	LcdFont font;

	int nbItems;
	std::vector<Item*> items;

};


extern Frame frame;

#endif /* INC_FRAME_HPP_ */
