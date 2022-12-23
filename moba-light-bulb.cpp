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

#include "moba-light-bulb.h"

BulbLight::BulbLight(uint8_t pin): pin{pin} {
    pinMode(pin, OUTPUT);
    off();
}

BulbLight::~BulbLight() {
    off();
}

void BulbLight::on() {
    digitalWrite(pin, INVERT_VAL_LOG(HIGH));
}

void BulbLight::off() {
    digitalWrite(pin, INVERT_VAL_LOG(LOW));
}

void BulbLight::handle() {
    return;
}
