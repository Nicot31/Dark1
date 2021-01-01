/**
 ******************************************************************************
 * File Name          : TOUCH.hpp
 * Description        : touch screen management for the XPT2046
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef INC_TOUCH_HPP_
#define INC_TOUCH_HPP_


/* Constants ----------------------------------------------------------------*/


/* Class --------------------------------------------------------------------*/
class TouchScreen {
public:
	TouchScreen(void);

	void Reset(void);
	void SetOrientation(int w, int h, int o);
	void GetXY(int *x, int *y);
	bool GetXYMedian(int *x, int *y);
	bool IsPenDown();
	void WaitPenUp();
	void WaitPenDown();

private:
	int Get(uint8_t address);
	int FastMedian(int *samples);
	bool Correction(int *x, int *y);

public:
	// screen
	int orientation;
	int width;
	int height;
	// touch
	int minXTouch;
	int minYTouch;
	int widthTouch;
	int heightTouch;
};


/* Variables ----------------------------------------------------------------*/
extern TouchScreen touch;


#endif /* INC_TOUCH_HPP_ */
