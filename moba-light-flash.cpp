
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

#include "moba-light-flash.h"

FlashLight::FlashLight(uint8_t pin, uint32_t tOn, uint32_t tOff): BulbLight{pin}, tOn{tOn}, tOff{tOff}, isActive{false} {
}

void FlashLight::handle() {
    if(!isActive) {
        return;
    }

    if(curState == HIGH) {
        toggle(tOff);
    } else {
        toggle(tOn);
    }
}

void FlashLight::toggle(uint32_t interval) {
    auto currentMillis = millis();
    
    if(currentMillis - prevTimestamp < interval) {
        return;
    }
    curState = !curState;
    digitalWrite(pin, INVERT_VAL_LOG(curState));
    prevTimestamp = currentMillis;
}

void FlashLight::on() {
    prevTimestamp = millis();
    isActive = true;
}

void FlashLight::off() {
    isActive = false;
    BulbLight::off();
}
