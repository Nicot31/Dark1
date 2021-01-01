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

// Register cab be 0 to 19
#define TOUCH_MIN	0   	// LOW = xMin, HIGH = yMin
#define TOUCH_SIZE	1		// LOW = width, HIGH = height

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
