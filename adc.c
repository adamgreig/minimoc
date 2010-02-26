// minimoc
// mini motor controller
// adc.c - adc related functionality
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

#include "adc.h"

// Read an ADC input, return result
uint16_t read_adc(uint8_t adc) {
    ADMUX = (1<<REFS0) | adc;                       //Select ADC channel
    ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADPS2);    //Enable with 1/16 clk
    while(ADCSRA & (1<<ADSC)) {}                    //Wait for conversion
    uint16_t high = ADCH;
    high <<= 8;
    return high | ADCL;                             //Return result
}

