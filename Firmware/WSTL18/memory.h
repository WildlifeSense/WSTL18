﻿/********************************************************************************

  memory.h: Header file for the memory module of WSTL18 firmware.
 
  Copyright (C) 2017 Nikos Vallianos <nikos@wildlifesense.com>
  
  This file is part of WSTL18 firmware.
  
  WSTL18 firmware is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  WSTL18 firmware is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  in the file COPYING along with this program.  If not,
  see <http://www.gnu.org/licenses/>.

  ********************************************************************************/

#ifndef MEMORY_H_
#define MEMORY_H_

// Memory chip select is PB2. Select and deselect memory chip as SPI slave.
#define MEMORY_CS_INIT			DDRB |= (1<<DDRB2)				// Set CS pin as output
#define MEMORY_CS_SELECT		PORTB &= ~(1 << PORTB2)			// Set CS pin LOW
#define MEMORY_CS_DESELECT		PORTB |= (1 << PORTB2)			// Set CS pin HIGH

void memoryInitialize(void);
void memoryTerminate(void);

void memoryWriteWord(uint16_t array_address, uint16_t written_word);
uint16_t memoryReadWord(uint16_t array_address);

uint16_t memoryScan(void);
void memoryReadStatusRegisters(void);								// Read status registers
uint8_t memoryGetStatusRegister1(void);
uint8_t memoryGetStatusRegister2(void);
void memoryWriteStatusRegister1(uint8_t status);					// Write status register 1

void memoryUltraDeepPowerDownEnter();								// Enter ultra-deep power down mode.
void memoryUltraDeepPowerDownExitBegin();								// Exit ultra-deep power down mode.
void memoryOTPLoad(void);
uint8_t memoryLogTemperature(uint16_t temperature_reading);			// Stores 16-bit temperature in memory, returns flags.


void memoryReadMFDID(void);
void memoryPrintMFDID(void);
#endif /* MEMORY_H_ */