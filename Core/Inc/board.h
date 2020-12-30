/**
  ******************************************************************************
  * File Name		: BOARD.h
  * Description		: This file provides code to interface the board hardware
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOARD_H
#define __BOARD_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "stm32f4xx_hal.h"

/* Constants -----------------------------------------------------------------*/
#define NB_LED	2
#define LED2	0
#define LED3	1

#define NB_KEY	2
#define KEY0	0
#define KEY1 	1

/* Structures -----------------------------------------------------------------*/


/* Functions -----------------------------------------------------------------*/
void LedSet(unsigned int Led, GPIO_PinState state);
void LedOn(unsigned int Led);
void LedOff(unsigned int Led);
void LedToggle(unsigned int Led);

int KeyTest(unsigned int key);

extern __IO uint32_t uwTick;
void Delay(uint32_t delay);


#ifdef __cplusplus
}
#endif
#endif // /*__BOARD_H */
