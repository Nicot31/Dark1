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
	void GetXY(int *x, int *y, bool raw);
	void GetXYMedian(int *x, int *y);

private:
	int Get(uint8_t address);
	int FastMedian(int *samples);
	void Correction(int *x, int *y);

public:
	int orientation;
	int width;
	int height;
	int minX, maxX;
	int minY, maxY;
};


/* Variables ----------------------------------------------------------------*/
extern int TouchPenInterrupt(void);
extern TouchScreen touch;


#endif /* INC_TOUCH_HPP_ */
