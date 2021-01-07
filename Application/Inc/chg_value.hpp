 /**
  ******************************************************************************
  * File Name   : chg_value.hpp
  * Description : 
  *
  * Created on  : 7 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


#ifndef INC_CHG_VALUE_HPP_
#define INC_CHG_VALUE_HPP_

#include "item.hpp"
#include "button.hpp"
#include "label.hpp"

/* Constants -----------------------------------------------------------------*/

/* Class ---------------------------------------------------------------------*/
class ChgValue : public Item {
public:
	ChgValue(int id, Point p, int width, int heigh);

	void SetDefaultColors(int back, int backActif, int border, int text);
	void SetDefaultBorderSize(int size);
	void SetDefaultFont(LcdFont font);

	void SetColors(int back, int backActif, int border, int text);
	void SetBorderSize(int size);
	void SetFont(LcdFont font);

	void SetRange(int min, int max, int step);
	void SetValue(int value);

	bool Event(int evt, Point& pos);	// pos is relative to button coordinates. Return true if event is processed

	void Draw(void);

	// Attributes
	Button* btnLeft;
	Button* btnRight;
	Label* text;
	int min;
	int max;
	int step;
	int value;

private:
	static int defaultBackColor;
	static int defaultBackColorActif;
	static int defaultBorderColor;
	static int defaultTextColor;
	static int defaultBorderSize;
	static LcdFont defaultFont;
};





#endif /* INC_CHG_VALUE_HPP_ */
