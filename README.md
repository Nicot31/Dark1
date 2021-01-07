# Dark1

This project is based on a STM32F407EVT6 Dark board with a TFT LCD ILI9341 that include 
a touch screen based on XPT2046.

![alt text](https://github.com/Nicot31/Dark1/blob/master/pictures/STM32.png)
![alt text](https://github.com/Nicot31/Dark1/blob/master/pictures/LCD.png)

## Description
Based on FreeRTOS, this program manage a TFT LCD with a touch screen. 

It is edited with the STM32CubeIDE framewoark. The Core part is generated with STM32CubeMX, so written in C 
and the Application part uses C++.

### Modules
Name  | Description
----- | -----------
*LCD* | This class contains the LCD commands, the graphics functions and the text printing.
*TOUCH* | Touch screen management with pen Up/Down detection and position. This module include the touch screen calibration.
*CONFIG* | Allows to store and read value in the SRAM (RTC register). Usefull to keep touch screen configuration after power off.
*FRAME* | Is the core module for the GUI. It manages the pen events and the items drawing.
*ITEM* | Abstract class for all items to draw on the screen.
*BUTTON*| To display a button and detect the click.
*LABEL* | To display a static text that can't be clicked.
*CHGVALUE* | A control to change a value. It is composed with 2 buttons "<" and ">" with an integer value between.
