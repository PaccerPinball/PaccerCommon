/*
 * PaccerLib
 * =========
 * 
 * Library for the Paccer Pinball.
 * 
 * Created 2022-05-20
 * 
 * https://github.com/PaccerPinball/PaccerLib
 */


#ifndef PACCERLIB_H
#define PACCERLIB_H

#include <Arduino.h>
#include <LiquidCrystal.h>


// TODO LiquidCrystal_I2C support
// TODO functions like score(points), announce(str) for simulating scoring + goals
class PaccerLib {
    private:
        LiquidCrystal* lcd;
    public:
    __attribute__((unused)) explicit PaccerLib(LiquidCrystal* lcd);
        void printProgressively(const String& str, int delayMillis);
        void printRandomized(const String& str, int minDelay, int maxDelay);
};

#endif
