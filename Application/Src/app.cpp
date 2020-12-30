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


/*******************************************************************************
 * Say Hello :-)
 ******************************************************************************/
void Hello() {
	int x, y;
	char *msg = (char *)"Hello Thierry !";

	lcd.SetFont(Font_11x18);
	lcd.GetStringSize(msg, &x, &y);
	x = (lcd.width - x) / 2;
	y = (lcd.height - y) / 2;
	lcd.SetTextPos(x, y);
	lcd.SetFontColor(LCD_COLOR_ORANGE);
	lcd.TextPuts(msg);
	lcd.SetFontColor(LCD_COLOR_WHITE);
	lcd.Circle(100, 100, 50, false, LCD_COLOR_CYAN);
	lcd.DrawLine(100, 100, 300, 200, LCD_COLOR_BROWN);
}

/*******************************************************************************
 * Application initialization
 ******************************************************************************/
void AppInit() {
	int i;

	lcd.Init();
	lcd.Orientation(LCD_LANDSCAPE_1);
	touch.Reset();
	Hello();

	for (i = 30; i < 100; i += 10) {
		lcd.DrawHLine(10, 100, i, LCD_COLOR_GREEN);
		lcd.DrawVLine(100+i, 10, 100, LCD_COLOR_YELLOW);
	}
}

/*******************************************************************************
 * Application loop
 ******************************************************************************/
void AppLoop() {
	int x = 0, y = 0;
	int Res;
	char sMsg[30];


	// display Pen Status
	Res = TouchPenInterrupt();
	if (Res) {
		touch.GetXYMedian(&x, &y);
		sprintf(sMsg, "x=%05d, y=%05d", x, y);
		lcd.TextPutsAt(5, 5, sMsg);

		//touch.GetXY(&x, &y, false);
		//sprintf(sMsg, "x=%05d, y=%05d", x, y);
		//lcd.TextPutsAt(5, 30, sMsg);

		lcd.DrawPixel(x, y, LCD_COLOR_MAGENTA);
	}
	osDelay(10);

}

