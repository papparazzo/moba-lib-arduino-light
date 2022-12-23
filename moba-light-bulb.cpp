#include "moba-light-bulb.h"

BulbLight::BulbLight(uint8_t pin): pin{pin} {
    pinMode(pin, OUTPUT);
    off();
}

BulbLight::~BulbLight() {
    off();
}

void BulbLight::on() {
    digitalWrite(pin, INVERT_VAL_LOG(HIGH));
}

void BulbLight::off() {
    digitalWrite(pin, INVERT_VAL_LOG(LOW));
}

void BulbLight::handle() {
    return;
}
