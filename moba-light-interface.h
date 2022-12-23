#pragma once

//#ifdef INVERT
    #define INVERT_VAL_BIN(val) ~(val)
    #define INVERT_VAL_LOG(val) !(val)
//#else
//    #define INVERT_VAL_BIN(val) (val)
//    #define INVERT_VAL_LOg(val) (val)
//#endif

class InterfaceLight {
    public:
        virtual ~InterfaceLight() {}

        virtual void on() = 0;
        virtual void off() = 0;

        virtual void handle() = 0;
};
