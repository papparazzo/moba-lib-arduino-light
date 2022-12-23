
#pragma once

#include "moba-light-bulb.h"
#include "Arduino.h"

class NeonLight: public BulbLight {
    public:
        NeonLight(uint8_t pin);

        virtual void on();
        virtual void off();
        
        virtual void handle();

    protected:
        enum class State {
            OFF,
            RUNNING,
            STARTING
        };

        State state = State::OFF;

        uint8_t brightness;
        uint32_t interval; 
        uint32_t prevTimestamp;
        uint32_t prevTimestampEffect;  

        void flicker(unsigned long currentTimestamp);
};
