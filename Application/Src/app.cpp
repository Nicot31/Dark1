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
#include "frame.hpp"

/*******************************************************************************
 * Say Hello :-)
 ******************************************************************************/
void Hello() {
	Button* btn;
	Label* lbl;

	if (KeyTest(KEY1))
		lcd.Calibrate();

	lcd.SetFont(Font_11x18);
	lcd.SetFontColor(COLOR_WHITE);

	//lcd.SetFontColor(LCD_COLOR_ORANGE);
	//lcd.TextPutsCenterXY("Hello Thierry !");

	btn = new Button(1, Point(150, 50), 70, 30, "Go");
	btn->SetFont(Font_11x18);
	frame.Add(btn);

	btn = new Button(2, Point(50, 50), 70, 30, "Test");
	btn ->SetColor(COLOR_BLUE2, COLOR_BLUE, COLOR_BLACK);
	btn->SetColorActif(COLOR_BLUE, COLOR_BLUE2, COLOR_NONE);
	frame.Add(btn);

	Label::SetDefaultBorderSize(1);
	lbl = new Label(-1, Point(10, 100), 100, 25, "(LEFT)");
	frame.Add(lbl);
	lbl = new Label(-1, Point(10, 130), 100, 25, "(CENTER)");
	lbl->SetIndent(INDENT_CENTER);
	frame.Add(lbl);
	lbl = new Label(-1, Point(10, 160), 100, 25, "(RIGHT)");
	lbl->SetIndent(INDENT_RIGHT);
	frame.Add(lbl);

	frame.Draw();
}

/*******************************************************************************
 * Application initialization
 ******************************************************************************/
void AppInit() {
	lcd.Init();
	lcd.Orientation(LCD_LANDSCAPE_1);
	touch.Reset();
	frame.Init();
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

