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

extern uint8_t lowside[6];
extern uint8_t highside[6];
extern uint8_t bemfs[6];

void run() {
    unsigned int i;
    for(i=0; i<100; i++) {
        DRIVE_PORT = lowside[0];
        set_pwm(highside[0], 80);
        delay(2500);
        power_down();
        delay(750);

        DRIVE_PORT = lowside[1];
        set_pwm(highside[1], 80);
        delay(2500);
        power_down();
        delay(750);

        DRIVE_PORT = lowside[2];
        set_pwm(highside[2], 80);
        delay(2500);
        power_down();
        delay(750);

        DRIVE_PORT = lowside[3];
        set_pwm(highside[3], 80);
        delay(2500);
        power_down();
        delay(750);

        DRIVE_PORT = lowside[4];
        set_pwm(highside[4], 80);
        delay(2500);
        power_down();
        delay(750);

        DRIVE_PORT = lowside[5];
        set_pwm(highside[5], 80);
        delay(2500);
        power_down();
        delay(750);
    }
}

int main() {
    init_io();
    power_down();
    //wdt_enable(WDTO_120MS);
    light_led(LED_OK);

    if((read_adc(6) / 2) < 230) {
        clear_led(LED_OK);
        for(;;) {
            light_led(LED_ERR);
            delay(100000);
            clear_led(LED_ERR);
            delay(100000);
        }
    }

    startup();
    run();
    power_down();
}
