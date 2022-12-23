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

#include "moba-light-interface.h"
#include "Arduino.h"

class FairyLight: public InterfaceLight {
    public:
        FairyLight(uint8_t pins[], uint8_t pinsCount, uint32_t interval = ON_INTERVALL);

        virtual ~FairyLight();

        virtual void on();
        virtual void off();

        virtual void handle();

    protected:     
        static const uint32_t ON_INTERVALL = 5;
        
        const uint8_t *pins;
        const uint8_t pinsCount;
        bool isActive;
        unsigned int ptr;
        
        uint32_t interval;
        uint32_t prevTimestamp;
};
