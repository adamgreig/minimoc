// minimoc
// mini motor controller
// pins.h - which pins map to which functions
// copyright 2010 adam greig
//
//  This file is part of minimoc.
//  minimoc is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  minimoc is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  You should have received a copy of the GNU General Public License
//  along with minimoc.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

// Bridge driving channels
#define AP PB3
#define AM PB5
#define BP PB2
#define BM PB4
#define CP PB1
#define CM PB0
#define DRIVE_PORT PORTB
#define DRIVE_DDR DDRB

// Polarity to drive the bridge
#define HIGH 1
#define LOW 0

// Back EMF ADC multiplexer masks
#define BEMF_A 1
#define BEMF_B 0
#define BEMF_C 7
#define BEMF_A_PIN PC1
#define BEMF_B_PIN PC0
#define BEMF_C_PIN PC0
#define BEMF_PORT PORTC
#define BEMF_DDR DDRC
#define VBATT 6

// Status LEDs
#define LED_OK PD0
#define LED_ERR PD1
#define LED_PORT PORTD
#define LED_DDR DDRD

// Address solder jumper
#define ADDR1 PD2
#define ADDR2 PD3
#define ADDR_PIN PIND
#define ADDR_DDR DDRD

