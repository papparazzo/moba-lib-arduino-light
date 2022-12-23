#include "moba-light-neon.h"
#include "Arduino.h"

NeonLight::NeonLight(uint8_t pin): BulbLight{pin} {
}

void NeonLight::on() {
    if(state != State::OFF) {
        return;
    }
    prevTimestamp = millis();
    analogWrite(pin, INVERT_VAL_BIN(3));
    interval = 500;
    state = State::STARTING;
}

void NeonLight::off() {
    state = State::OFF;
    BulbLight::off();
}

void NeonLight::handle() {
    auto currentTimestamp = millis();

    if(state == State::OFF || state == State::RUNNING) {
        return;
    }

    flicker(currentTimestamp);

    if (currentTimestamp - prevTimestamp > (uint16_t)(random(200, 400) * 10)) {
        state = State::RUNNING;
        digitalWrite(pin, INVERT_VAL_LOG(HIGH));
    }
}

void NeonLight::flicker(unsigned long currentTimestamp) {
    if (currentTimestamp - prevTimestampEffect < interval) {
        return;
    }

    if (brightness >= 200) {
        brightness = 3;
        interval = random(600, 1000);
    } else {
        brightness = random(3, 255);
        interval = 30;
    }
    analogWrite(pin, INVERT_VAL_BIN(brightness));
    prevTimestampEffect = currentTimestamp;
}