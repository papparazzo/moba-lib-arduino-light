#include "moba-light-halide.h"

HalideLight::HalideLight(uint8_t pin, uint32_t tOn, uint32_t tOff) : FlashLight{pin, tOn, tOff} {
}

void HalideLight::handle() {
    if((isActive && brightness == 255) || (!isActive && brightness == 0)) {
        return;
    }

    if(isActive) {
        changeBrightness(tOn, 1);
    } else {
        changeBrightness(tOff, -1);
    }
}

void HalideLight::changeBrightness(uint32_t interval, int8_t step) {
    auto currentMillis = millis();
    
    if(currentMillis - prevTimestamp < interval) {
        return;
    }
    brightness += step;
    analogWrite(pin, INVERT_VAL_BIN(brightness));
    prevTimestamp = currentMillis;
}

void HalideLight::off() {
    isActive = false;
}
