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

#pragma once

#include "moba-light-flash.h"

class HalideLight: public FlashLight {
    public:
        HalideLight(uint8_t pin, uint32_t tOn, uint32_t tOff);
        
        void off();

        virtual void handle();

    protected:
        static const uint32_t ON_INTERVALL = 5000;
        static const uint32_t OFF_INTERVALL = 10000;

    private:
        uint8_t  brightness = 0;

        void changeBrightness(uint32_t interval, int8_t step);
};
