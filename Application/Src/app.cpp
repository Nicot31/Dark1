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
#include "frame.hpp"

/*******************************************************************************
 * Say Hello :-)
 ******************************************************************************/
void Hello() {
	Button* btn;

	if (KeyTest(KEY1))
		lcd.Calibrate();

	lcd.SetFont(Font_11x18);
	lcd.SetFontColor(COLOR_WHITE);

	//lcd.SetFontColor(LCD_COLOR_ORANGE);
	//lcd.TextPutsCenterXY("Hello Thierry !");

	btn = new Button(Point(50, 50), 70, 30, COLOR_BLUE2, COLOR_BLUE, 2, "Test", COLOR_BLACK, Font_11x18);
	btn->SetColorActif(COLOR_BLUE, COLOR_BLUE2, COLOR_NONE);
	frame.Add(btn);
	btn = new Button(Point(150, 50), 70, 30, COLOR_GRAY2, COLOR_GRAY, 2, "Go", COLOR_WHITE, Font_11x18);
	btn->SetColorActif(COLOR_GRAY, COLOR_GRAY2, COLOR_NONE);
	frame.Add(btn);
	frame.Draw();
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
	static bool penDown = false;
	static Point pos = Point(0, 0);
	int Res;

	// display Pen Status
	Res = touch.IsPenDown();
	if (Res) {
		// Pen is down
		if (touch.GetXYMedian(pos)) {
			// Data is available
			if (penDown) {
				frame.EventManagement(EVT_PEN_MOVE, pos);
			} else {
				penDown = true;
				frame.EventManagement(EVT_PEN_DOWN, pos);
			}
		}
	} else if (penDown) {
		// Pen goes up
		penDown = false;
		frame.EventManagement(EVT_PEN_UP, pos);
	}

	osDelay(10);

}

