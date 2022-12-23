#pragma once

#include "moba-light-interface.h"
#include "Arduino.h"

class BulbLight: public InterfaceLight {
    public:
        BulbLight(uint8_t pin);
        virtual ~BulbLight();

        virtual void on();
        virtual void off();

        virtual void handle();

    protected:
        const uint8_t pin;
};
