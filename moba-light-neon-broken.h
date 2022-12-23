
#pragma once

#include "moba-light-neon.h"
#include "Arduino.h"

class BrokenNeonLight: public NeonLight {
    public:
        BrokenNeonLight(uint8_t pin);
        
        virtual void handle();
};
