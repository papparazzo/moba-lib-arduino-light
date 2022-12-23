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
