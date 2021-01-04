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

#include "util.hpp"

/* Constants -----------------------------------------------------------------*/

/* Virtual Class -------------------------------------------------------------*/
class Item {
public:
	Item();
	bool IsEnable(void);
	bool IsActif(void);
	virtual void Enable(bool fEnable);
	virtual void Activate(bool fAct);
	virtual void Draw(void);
	virtual bool Event(int evt, Point& pos);

	// Attributes
	Rectangle rect;		// rectangle for the Item position
	bool fEnable;
	bool fActif;
	int ID;
};

#endif /* INC_ITEM_HPP_ */
