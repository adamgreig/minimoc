// minimoc
// mini motor controller
// motor.h - BLDC motor control functions
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

#include "motor.h"


uint8_t lowside[6] = { 1<<AM, 1<<AM, 1<<BM, 1<<BM, 1<<CM, 1<<CM };
uint8_t highside[6] = { BP, CP, CP, AP, AP, BP };
uint8_t bemfs[6] = { BEMF_C, BEMF_B, BEMF_A, BEMF_C, BEMF_B, BEMF_A };


void startup() {
    unsigned long int ontime = 8000;
    unsigned long int offtime = 2400;
    for(; ontime > 2000; ontime -= 100, offtime -= 30) {
        DRIVE_PORT = lowside[0];
        set_pwm(highside[0], 80);
        delay(ontime);
        power_down();
        delay(offtime);

        DRIVE_PORT = lowside[1];
        set_pwm(highside[1], 80);
        delay(ontime);
        power_down();
        delay(offtime);

        DRIVE_PORT = lowside[2];
        set_pwm(highside[2], 80);
        delay(ontime);
        power_down();
        delay(offtime);

        DRIVE_PORT = lowside[3];
        set_pwm(highside[3], 80);
        delay(ontime);
        power_down();
        delay(offtime);

        DRIVE_PORT = lowside[4];
        set_pwm(highside[4], 80);
        delay(ontime);
        power_down();
        delay(offtime);

        DRIVE_PORT = lowside[5];
        set_pwm(highside[5], 80);
        delay(ontime);
        power_down();
        delay(offtime);

    }
 
}
