/*
 *  Project:    moba-lib-arduino-light
 *
 *  Copyright (C) 2022 Stefan Paproth <pappi-@gmx.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/agpl.txt>.
 *
 */

#include "moba-light-neon.h"
#include "Arduino.h"

NeonLight::NeonLight(uint8_t pin): BulbLight{pin} {
}

void NeonLight::on() {
    if(state != State::OFF) {
        return;
    }
    prevTimestamp = millis();
    analogWrite(pin, INVERT_VAL_BIN(3));
    interval = 500;
    state = State::STARTING;
}

void NeonLight::off() {
    state = State::OFF;
    BulbLight::off();
}

void NeonLight::handle() {
    auto currentTimestamp = millis();

    if(state == State::OFF || state == State::RUNNING) {
        return;
    }

    flicker(currentTimestamp);

    if (currentTimestamp - prevTimestamp > (uint16_t)(random(200, 400) * 10)) {
        state = State::RUNNING;
        digitalWrite(pin, INVERT_VAL_LOG(HIGH));
    }
}

void NeonLight::flicker(unsigned long currentTimestamp) {
    if (currentTimestamp - prevTimestampEffect < interval) {
        return;
    }

    if (brightness >= 200) {
        brightness = 3;
        interval = random(600, 1000);
    } else {
        brightness = random(3, 255);
        interval = 30;
    }
    analogWrite(pin, INVERT_VAL_BIN(brightness));
    prevTimestampEffect = currentTimestamp;
}