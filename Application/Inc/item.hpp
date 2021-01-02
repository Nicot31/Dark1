/**
 ******************************************************************************
 * File Name   : item.hpp
 * Description :
 *
 * Created on  : 2 janv. 2021
 *     Author  : Thierry
 ******************************************************************************
 */

#ifndef INC_ITEM_HPP_
#define INC_ITEM_HPP_

/* Constants -----------------------------------------------------------------*/

/* Virtual Class -------------------------------------------------------------*/
class Item {
public:
	Item();
	void Enable(bool ena);
	virtual void Draw(void) = 0;

	// Attributes
	bool enable;
};

#endif /* INC_ITEM_HPP_ */
