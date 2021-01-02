/**
 ******************************************************************************
 * File Name          : TOUCH.hpp
 * Description        : touch screen management for the XPT2046
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef INC_TOUCH_HPP_
#define INC_TOUCH_HPP_

#include "util.hpp"

/* Constants ----------------------------------------------------------------*/


/* Class --------------------------------------------------------------------*/
class TouchScreen {
public:
	TouchScreen(void);

	void Reset(void);
	void SetOrientation(int w, int h, int o);
	void GetXY(int *x, int *y);
	bool GetXYMedian(int *x, int *y);
	bool GetXYMedian(Point& p);
	bool IsPenDown();
	void WaitPenUp();
	void WaitPenDown();

private:
	int Get(uint8_t address);
	int FastMedian(int *samples);
	bool Correction(int *x, int *y);

public:
	int orientation;
	// screen
	int widthLCD;
	int heightLCD;
	// touch
	int xOffsetTouch;
	int yOffsetTouch;
	int widthTouch;
	int heightTouch;
};


/* Variables ----------------------------------------------------------------*/
extern TouchScreen touch;


#endif /* INC_TOUCH_HPP_ */
