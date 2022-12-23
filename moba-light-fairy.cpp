#include "moba-light-fairy.h"

FairyLight::FairyLight(uint8_t pins[], uint8_t pinsCount, uint32_t interval):
pins{pins}, pinsCount{pinsCount}, isActive{false}, ptr{0}, interval{interval} {
    for (uint8_t i = 0; i < pinsCount; ++i) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], INVERT_VAL_LOG(LOW));
    }
}

FairyLight::~FairyLight() {
    off();
}

void FairyLight::on() {
    prevTimestamp = millis();
    isActive = true;
}

void FairyLight::off() {
    isActive = false;
    digitalWrite(pins[ptr], INVERT_VAL_LOG(LOW));
}

void FairyLight::handle() {
    if(!isActive) {
        return;
    }

    auto currentMillis = millis();
    if (currentMillis - prevTimestamp < interval) {
        return;
    }

    digitalWrite(pins[ptr], INVERT_VAL_LOG(LOW));
    ptr = (ptr + 1) % pinsCount;   
    digitalWrite(pins[ptr], INVERT_VAL_LOG(HIGH));
    prevTimestamp = currentMillis;
}
