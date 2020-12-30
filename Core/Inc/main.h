/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOE
#define KEY0_Pin GPIO_PIN_4
#define KEY0_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOA
#define PEN_INT_Pin GPIO_PIN_5
#define PEN_INT_GPIO_Port GPIOC
#define LCD_BL_Pin GPIO_PIN_1
#define LCD_BL_GPIO_Port GPIOB
#define TFT_FSMC_D4_Pin GPIO_PIN_7
#define TFT_FSMC_D4_GPIO_Port GPIOE
#define TFT_FSMC_D5_Pin GPIO_PIN_8
#define TFT_FSMC_D5_GPIO_Port GPIOE
#define TFT_FSMC_D6_Pin GPIO_PIN_9
#define TFT_FSMC_D6_GPIO_Port GPIOE
#define TFT_FSMC_D7_Pin GPIO_PIN_10
#define TFT_FSMC_D7_GPIO_Port GPIOE
#define TFT_FSMC_D8_Pin GPIO_PIN_11
#define TFT_FSMC_D8_GPIO_Port GPIOE
#define TFT_FSMC_D9_Pin GPIO_PIN_12
#define TFT_FSMC_D9_GPIO_Port GPIOE
#define TFT_FSMC_D10_Pin GPIO_PIN_13
#define TFT_FSMC_D10_GPIO_Port GPIOE
#define TFT_FSMC_D11_Pin GPIO_PIN_14
#define TFT_FSMC_D11_GPIO_Port GPIOE
#define TFT_FSMC_D12_Pin GPIO_PIN_15
#define TFT_FSMC_D12_GPIO_Port GPIOE
#define TFT_FSMC_D13_Pin GPIO_PIN_8
#define TFT_FSMC_D13_GPIO_Port GPIOD
#define TFT_FSMC_D14_Pin GPIO_PIN_9
#define TFT_FSMC_D14_GPIO_Port GPIOD
#define TFT_FSMC_D15_Pin GPIO_PIN_10
#define TFT_FSMC_D15_GPIO_Port GPIOD
#define TFT_FSMC_A18_Pin GPIO_PIN_13
#define TFT_FSMC_A18_GPIO_Port GPIOD
#define TFT_FSMC_D0_Pin GPIO_PIN_14
#define TFT_FSMC_D0_GPIO_Port GPIOD
#define TFT_FSMC_D1_Pin GPIO_PIN_15
#define TFT_FSMC_D1_GPIO_Port GPIOD
#define JTAG_TMS_Pin GPIO_PIN_13
#define JTAG_TMS_GPIO_Port GPIOA
#define JTAG_TCK_Pin GPIO_PIN_14
#define JTAG_TCK_GPIO_Port GPIOA
#define JTAG_TDI_Pin GPIO_PIN_15
#define JTAG_TDI_GPIO_Port GPIOA
#define TFT_FSMC_D2_Pin GPIO_PIN_0
#define TFT_FSMC_D2_GPIO_Port GPIOD
#define TFT_FSMC_D3_Pin GPIO_PIN_1
#define TFT_FSMC_D3_GPIO_Port GPIOD
#define TFT_FSMC_NOE_Pin GPIO_PIN_4
#define TFT_FSMC_NOE_GPIO_Port GPIOD
#define TFT_FSMC_NWE_Pin GPIO_PIN_5
#define TFT_FSMC_NWE_GPIO_Port GPIOD
#define JTAG_TDO_Pin GPIO_PIN_3
#define JTAG_TDO_GPIO_Port GPIOB
#define JTAG_TRST_Pin GPIO_PIN_4
#define JTAG_TRST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
