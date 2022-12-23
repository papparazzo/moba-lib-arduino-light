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

#include "moba-light-fairy.h"

FairyLight::FairyLight(uint8_t pins[], uint8_t pinsCount, uint32_t interval):
pins{pins}, pinsCount{pinsCount}, isActive{false}, ptr{0}, interval{interval} {
    for (uint8_t i = 0; i < pinsCount; ++i) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], INVERT_VAL_LOG(LOW));
    }
}

FairyLight::~FairyLight() {
    off();
}

void FairyLight::on() {
    prevTimestamp = millis();
    isActive = true;
}

void FairyLight::off() {
    isActive = false;
    digitalWrite(pins[ptr], INVERT_VAL_LOG(LOW));
}

void FairyLight::handle() {
    if(!isActive) {
        return;
    }

    auto currentMillis = millis();
    if (currentMillis - prevTimestamp < interval) {
        return;
    }

    digitalWrite(pins[ptr], INVERT_VAL_LOG(LOW));
    ptr = (ptr + 1) % pinsCount;   
    digitalWrite(pins[ptr], INVERT_VAL_LOG(HIGH));
    prevTimestamp = currentMillis;
}
