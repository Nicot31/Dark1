 /**
  ******************************************************************************
  * File Name   : util.hpp
  * Description : 
  *
  * Created on  : 2 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


#ifndef INC_UTIL_HPP_
#define INC_UTIL_HPP_

/* Constants -----------------------------------------------------------------*/

// Events
#define EVT_PEN_DOWN	1
#define EVT_PEN_UP		2
#define EVT_PEN_MOVE	3

// Text indentation
#define INDENT_LEFT		1
#define INDENT_CENTER	2
#define INDENT_RIGHT	3

/* Class ---------------------------------------------------------------------*/
class Point {
public:
	Point(int x=0, int y=0);
	void Add(int width, int height);
	Point Shift(int x, int y);
	Point Shift(Point& offset);

	// Attributes
	int x;
	int y;
};


/* Class ---------------------------------------------------------------------*/
class Rectangle {
public:
	Rectangle(void);
	Rectangle(int x, int y, int width, int height);
	Rectangle(Point& p, int width, int height);
	bool IsPointInside(int x, int y);
	bool IsPointInside(Point& p);

	// Attributes
	Point p1;
	Point p2;
	int width;
	int height;
};




#endif /* INC_UTIL_HPP_ */
