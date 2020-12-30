/**
 ******************************************************************************
 * File Name		: board.c
 * Description		: This file provides code for the LCD driver
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "board.h"

/* Global Variables ----------------------------------------------------------*/
uint16_t        LedPin[NB_LED] = {GPIO_PIN_6, GPIO_PIN_7};
uint16_t 		KeyPin[NB_KEY] = {GPIO_PIN_4, GPIO_PIN_3};

/* Functions -----------------------------------------------------------------*/
/*******************************************************************************
 * Set the LED state, led can be LED2 or LED3
 ******************************************************************************/
void LedSet(unsigned int Led, GPIO_PinState state)
{
	if (Led >= NB_LED) return;
	HAL_GPIO_WritePin(GPIOA, LedPin[Led], state);
}

/*******************************************************************************
 * LED ON, led can be LED2 or LED3
 ******************************************************************************/
void LedOn(unsigned int Led)
{
	if (Led >= NB_LED) return;
	HAL_GPIO_WritePin(GPIOA, LedPin[Led], GPIO_PIN_RESET);
}

/*******************************************************************************
 * LED OFF, led can be LED2 or LED3
 ******************************************************************************/
void LedOff(unsigned int Led)
{
	if (Led >= NB_LED) return;
	HAL_GPIO_WritePin(GPIOA, LedPin[Led], GPIO_PIN_SET);
}

/*******************************************************************************
 * Toggle the LED, led can be LED2 or LED3
 ******************************************************************************/
void LedToggle(unsigned int Led)
{
	if (Led >= NB_LED) return;
	HAL_GPIO_TogglePin(GPIOA, LedPin[Led]);
}

/*******************************************************************************
 * Test if a key is pressed, key can be K0, K1 or K_UP
 ******************************************************************************/
int KeyTest(unsigned int key)
{
	GPIO_PinState res;

	if (key >= NB_KEY) return 0;
	res = HAL_GPIO_ReadPin(GPIOE, KeyPin[key]);

	// invert result for KEY0 and KEY1
	if ((key == KEY0) || (key == KEY1)) {
		if (res == GPIO_PIN_RESET) return 1;
		else return 0;
	}
	return res;
}


/*******************************************************************************
 * Delay the execution. The delay is in ms
 ******************************************************************************/
void Delay(uint32_t delay)
{
	uint32_t stop = uwTick + delay;
	while (stop > uwTick);
}
