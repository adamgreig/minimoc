// minimoc
// mini motor controller
// util.h - various utility functions
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

#include "util.h"

void delay(unsigned long int period) {
    while(period--)
        asm("nop\r\n");
}


void error() {
    clear_led(LED_OK);
    for(;;) {
        light_led(LED_ERR);
        delay(100000);
        clear_led(LED_ERR);
        delay(100000);
    }
}
