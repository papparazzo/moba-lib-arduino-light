#include "moba-light-neon-broken.h"
#include "Arduino.h"

BrokenNeonLight::BrokenNeonLight(uint8_t pin): NeonLight{pin} {
}

void BrokenNeonLight::handle() {
    auto currentTimestamp = millis();

    if(state == State::OFF) {
        return;
    }

    if(state == State::RUNNING) {
        // FIXME If sometimes broken == true
        if (currentTimestamp - prevTimestamp > (uint16_t)(random(400, 500) * 10)) {
            state = State::STARTING;
            prevTimestamp = currentTimestamp;
        }
        return;
    }

    flicker(currentTimestamp);

    if (currentTimestamp - prevTimestamp > (uint16_t)(random(100, 300) * 10)) {
        state = State::RUNNING;
        analogWrite(pin, INVERT_VAL_BIN(3));
        prevTimestamp = currentTimestamp;
    }
}
