#pragma once

#include "moba-light-bulb.h"

class FlashLight: public BulbLight {
    public:
        FlashLight(uint8_t pin, uint32_t tOn, uint32_t tOff);

        virtual void on();
        virtual void off();

        virtual void handle();
    
    protected:
        const uint32_t tOn;
        const uint32_t tOff;
        
        uint32_t prevTimestamp;
        bool     isActive;

    private:
        uint8_t  curState;
        
        void toggle(uint32_t interval);
};
