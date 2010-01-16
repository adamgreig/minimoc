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
#include <util/delay.h>

#include "pins.h"

// Initialise GPIOs
void init_io() {
    DRIVE_DDR = (1<<AP) | (1<<AM) | (1<<BP) | (1<<BM) | (1<<CP) | (1<<CM);
    BEMF_DDR = (0<<BEMF_A) | (0<<BEMF_B) | (0<<BEMF_C);
    LED_DDR = (1<<LED_OK) | (1<<LED_ERR);
}

// Stop all drive activity
void power_down() {
    if(LOWSIDE_POL == LOW) {
        DRIVE_PORT = (1<<AM) | (1<<BM) | (1<<CM);
    } else {
        DRIVE_PORT = 0;
    }
    LED_PORT = 0;
}

// Turn on I2C slave functionality
void init_i2c() {
    //TODO work out a suitable I²C address
    uint8_t address = 0x40;
    address |= (ADDR_PIN | ((1<<ADDR1)|(1<<ADDR2)));

    //Bit rate 100kHz
    TWBR = 32;
    TWCR = (1<<TWEA) | (1<<TWEN);
    TWAR = address << 1;
}

// Light up an LED
void light_led(uint8_t led) {
    LED_PORT |= (1<<led);
}

// Clear an LED
void clear_led(uint8_t led) {
    LED_PORT &= ~(1<<led);
}

// Read an ADC input, return result
uint16_t read_adc(uint8_t adc) {
    ADMUX = (1<<REFS0) | adc;                       //Select ADC channel
    ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADPS2);    //Enable with 1/16 clk
    while(ADCSRA & (1<<ADSC)) {}                    //Wait for conversion
    return (uint16_t)(ADCH<<8 | ADCL);              //Return result
}

// Set PWM output on one channel
void set_pwm(uint8_t pin, uint8_t dutycycle) {
    if(dutycycle < 0 || dutycycle > 255)            //Check dutycycle is valid
        return;

    if((pin == AM || pin == BM || pin == CM) && LOWSIDE_POL == LOW)
        dutycycle = 255 - dutycycle;                //Compensate for polarity

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
        return;
    }
}

int main() {
    init_io();
    power_down();
    init_i2c();
    wdt_enable(WDTO_120MS);

    for(;;) {
        wdt_reset();
    }
}
