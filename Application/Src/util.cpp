 /**
  ******************************************************************************
  * File Name   : util.cpp
  * Description : 
  *
  * Created on  : 2 janv. 2021
  *     Author  : Thierry
  ******************************************************************************
  */


/* Includes -----------------------------------------------------------------*/
#include "util.hpp"
/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/

/* Methods ------------------------------------------------------------------*/

/* Class --------------------------------------------------------------------*/
Point::Point(int px, int py) {
	x = px;
	y = py;
}

void Point::Add(int width, int height) {
	x += width;
	y += height;
}

Point Point::Shift(int sx, int sy) {
	return Point(x + sx, y + sy);
}


/* Class --------------------------------------------------------------------*/

Rectangle::Rectangle() {
	p1 = p2 = Point(0, 0);
	width = height = 0;
}

	// x, y is the upper left corner
Rectangle::Rectangle(int x, int y, int w, int h) {
	width = w;
	height = h;
	p1 = Point(x, y);
	p2 = p1.Shift(width, height);
}

Rectangle::Rectangle(Point p, int w, int h) {
	width = w;
	height = h;
	p1 = p;
	p2 = p.Shift(width, height);
}

bool Rectangle::IsPointInside(int x, int y) {
	if ((x >= p1.x) && (x <= p2.x) && (y >= p1.y) && (y <= p2.y))
		return true;
	return false;
}

bool Rectangle::IsPointInside(Point p) {
	if ((p.x >= p1.x) && (p.x <= p2.x) && (p.y >= p1.y) && (p.y <= p2.y))
		return true;
	return false;
}

