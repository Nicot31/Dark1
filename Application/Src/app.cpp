/*
 * app.c
 *
 *  Created on: Dec 29, 2020
 *      Author: Thierry
 */
#include <stdio.h>

#include "app.hpp"
#include "cmsis_os.h"
#include "board.h"
#include "lcd.hpp"
#include "touch.hpp"
#include "config.hpp"
#include "util.hpp"
#include "button.hpp"

/*******************************************************************************
 * Say Hello :-)
 ******************************************************************************/
void Hello() {

	if (KeyTest(KEY1))
		lcd.Calibrate();

	lcd.SetFont(Font_11x18);
	lcd.SetFontColor(LCD_COLOR_WHITE);

	//lcd.SetFontColor(LCD_COLOR_ORANGE);
	//lcd.TextPutsCenterXY("Hello Thierry !");
	Button btn = Button(Point(50, 50), 70, 30, LCD_COLOR_BLUE2, LCD_COLOR_BLUE, 2, "Test", LCD_COLOR_BLACK, Font_11x18);
	btn.Draw();
	btn = Button(Point(150, 50), 70, 30, LCD_COLOR_GRAY2, LCD_COLOR_GRAY, 2, "Go", LCD_COLOR_WHITE, Font_11x18);
	btn.Draw();
}

/*******************************************************************************
 * Application initialization
 ******************************************************************************/
void AppInit() {
	lcd.Init();
	lcd.Orientation(LCD_LANDSCAPE_1);
	touch.Reset();
	Hello();
}

/*******************************************************************************
 * Application loop
 ******************************************************************************/
void AppLoop() {
	static int oldX, oldY;
	static bool penDown = false;
	int x = 0, y = 0;
	int Res;
	//char sMsg[30];

	// display Pen Status
	Res = touch.IsPenDown();
	if (Res) {
		if (touch.GetXYMedian(&x, &y)) {
			if (penDown) {
				lcd.Line(oldX, oldY, x, y, LCD_COLOR_MAGENTA);
			} else {
				penDown = true;
				lcd.DrawPixel(x, y, LCD_COLOR_MAGENTA);
			}
			oldX = x;
			oldY = y;
		}
	} else if (penDown) {
		penDown = false;
	}

	osDelay(10);

}

