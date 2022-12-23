
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
