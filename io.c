// minimoc
// mini motor controller
// io.c - I/O manipulations including PWM
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

#include "io.h"

// Initialise GPIOs
void init_io() {
    DRIVE_DDR = (1<<AP) | (1<<AM) | (1<<BP) | (1<<BM) | (1<<CP) | (1<<CM);
    BEMF_DDR = (0<<BEMF_A) | (0<<BEMF_B) | (0<<BEMF_C);
    LED_DDR = (1<<LED_OK) | (1<<LED_ERR);
}

// Stop all drive activity
void power_down() {
    DRIVE_PORT = 0;
}

// Set PWM output on one channel
void set_pwm(uint8_t pin, uint8_t dutycycle) {
    if(dutycycle < 0 || dutycycle > 255)            //Check dutycycle is valid
        return;

    if(pin == PB1) {
        // Timer 1, OC1A
        TCCR2A = TCCR2B = 0;
        TCCR1A = (1<<COM1A1) | (1<<WGM10);
        TCCR1B = (1<<CS11) | (1<<CS10);
        OCR1A  = dutycycle;
    } else if(pin == PB2) {
        // Timer 1, OC1B
        TCCR2A = TCCR2B = 0;
        TCCR1A = (1<<COM1B1) | (1<<WGM10);
        TCCR1B = (1<<CS11) | (1<<CS10);
        OCR1B  = dutycycle;
    } else if(pin == PB3) {
        // Timer 2, OC2A
        TCCR1A = TCCR1B = 0;
        TCCR2A = (1<<COM2A1) | (1<<WGM20);
        TCCR2B = (1<<CS11) | (1<<CS10);
        OCR2A  = dutycycle;
    } else {
        // Invalid pin
        light_led(LED_ERR);
        return;
    }
}
