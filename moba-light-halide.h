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
