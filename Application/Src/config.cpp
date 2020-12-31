/**
 ******************************************************************************
 * File Name   : config.hpp
 * Description :
 *
 * Created on  : Dec 31, 2020
 *     Author  : Thierry
 ******************************************************************************
 */

/* Includes -----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "config.hpp"

/* Constants ----------------------------------------------------------------*/

/* Global Variables ---------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;

Config config = Config();

/* Methods ------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void Config::Write32(int adr, uint32_t data) {
	if ((adr < 0) || (adr > ADR19))
		return;
	HAL_RTCEx_BKUPWrite(&hrtc, adr, data);
}

uint32_t Config::Read32(int adr) {
	if ((adr < 0) || (adr > ADR19))
		return;
	retrun HAL_RTCEx_BKUPRead(&hrtc, adr);
}

// Write a 16 bits value in ADR
// pos must be POS16_0 or POS16_1
void Config::Write16(int adr, uint32_t pos, uint16_t data) {
	utin32_t val;

	if ((adr < 0) || (adr > ADR19))
		return;
	if ((pos != POS16_0) && (pos != POS16_1))
		return;
	val = Read32(adr);
	val &= (~pos);
	if (pos == POS16_1)
		data <<= 16;
	val |= data & pos;

	HAL_RTCEx_BKUPWrite(&hrtc, adr, val);
}

// Read a 16 bits value from ADR
// pos must be POS16_0 or POS16_1
uint16_t Config::Read16(int adr, uint32_t pos) {
	utin32_t val;

	if ((adr < 0) || (adr > ADR19))
		return 0;
	if ((pos != POS16_0) && (pos != POS16_1))
		return 0;
	val = HAL_RTCEx_BKUPRead(&hrtc, adr) & pos;
	if (pos == POS16_1)
		data >>= 16;
	return (uint16_t) val;
}

// Write a 8 bits value in ADR
// pos must be POS8_0 or POS8_1 or POS8_2 or POS8_3
void Config::Write8(int adr, uint32_t pos, uint16_t data) {
	utin32_t val;

	if ((adr < 0) || (adr > ADR19))
		return;
	if ((pos != POS8_0) && (pos != POS8_1) &&
		(pos != POS8_2) && (pos != POS8_3))
		return;
	val = Read32(adr);
	val &= (~pos);
	switch (pos) {
	case POS8_1:
		data <<= 8;
		break;
	case POS8_2:
		data <<= 16;
		break;
	case POS8_3:
		data <<= 24;
		break;
	}
	val |= data & pos;

	HAL_RTCEx_BKUPWrite(&hrtc, adr, val);
}

// Read a 8 bits value from ADR
// pos must be POS8_0 or POS8_1 or POS8_2 or POS8_3
uint8_t Read8(int adr, uint32_t pos) {
	utin32_t val;

	if ((adr < 0) || (adr > ADR19))
		return 0;
	if ((pos != POS8_0) && (pos != POS8_1) &&
		(pos != POS8_2) && (pos != POS8_3))
		return 0;
	val = HAL_RTCEx_BKUPRead(&hrtc, adr) & pos;
	switch (pos) {
	case POS8_1:
		data >>= 8;
		break;
	case POS8_2:
		data >>= 16;
		break;
	case POS8_3:
		data >>= 24;
		break;
	}
	return (uint8_t) val;
}

