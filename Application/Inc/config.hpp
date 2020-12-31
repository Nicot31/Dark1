 /**
  ******************************************************************************
  * File Name   : config.hpp
  * Description : 
  *
  * Created on  : Dec 31, 2020
  *     Author  : Thierry
  ******************************************************************************
  */

#ifndef INC_CONFIG_HPP_
#define INC_CONFIG_HPP_

/* Constants -----------------------------------------------------------------*/
#define ADR0	0
#define ADR1	1
#define ADR2	2
#define ADR3	3
#define ADR4	4
#define ADR5	5
#define ADR6	6
#define ADR7	7
#define ADR8	8
#define ADR9	9
#define ADR10	10
#define ADR11	11
#define ADR12	12
#define ADR13	13
#define ADR14	14
#define ADR15	15
#define ADR16	16
#define ADR17	17
#define ADR18	18
#define ADR19	19

#define POS16_0	0x0000FFFF	// 16 low bits
#define POS16_1	0xFFFF0000	// 16 High bits

#define POS8_0	0x000000FF
#define POS8_1	0x0000FF00
#define POS8_2	0x00FF0000
#define POS8_3	0xFF000000

/* Class ---------------------------------------------------------------------*/
class Config {
public:
	void Write32(int adr, uint32_t data);
	void Write16(int adr, uint32_t pos, uint16_t data);
	void Write8(int adr, uint32_t pos, uint8_t data);
	uint32_t Read32(int adr);
	uint16_t Read16(int adr, uint32_t pos);
	uint8_t  Read8(int adr, uint32_t pos);
};

extern Config config;


#endif /* INC_CONFIG_HPP_ */
