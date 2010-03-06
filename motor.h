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

#pragma once
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "pins.h"
#include "led.h"
#include "io.h"
#include "util.h"
#include "adc.h"

void startup();
void run();
void check_bemf();

