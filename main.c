// minimoc
// mini motor controller
// main.c - bldc control central!
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

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>

#include "pins.h"
#include "led.h"
#include "motor.h"
#include "io.h"
#include "adc.h"
#include "util.h"

int main() {
    init_io();
    power_down();
    //wdt_enable(WDTO_120MS);
    light_led(LED_OK);

    if(read_adc(VBATT) < 460) {
        error();
    }

    startup();
    sei();
    run();
    power_down();
}
