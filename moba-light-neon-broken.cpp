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

#include "moba-light-neon-broken.h"
#include "Arduino.h"

BrokenNeonLight::BrokenNeonLight(uint8_t pin): NeonLight{pin} {
}

void BrokenNeonLight::handle() {
    auto currentTimestamp = millis();

    if(state == State::OFF) {
        return;
    }

    if(state == State::RUNNING) {
        // FIXME If sometimes broken == true
        if (currentTimestamp - prevTimestamp > (uint16_t)(random(400, 500) * 10)) {
            state = State::STARTING;
            prevTimestamp = currentTimestamp;
        }
        return;
    }

    flicker(currentTimestamp);

    if (currentTimestamp - prevTimestamp > (uint16_t)(random(100, 300) * 10)) {
        state = State::RUNNING;
        analogWrite(pin, INVERT_VAL_BIN(3));
        prevTimestamp = currentTimestamp;
    }
}
