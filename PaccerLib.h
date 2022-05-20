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


// TODO functions like score(points), announce(str) for simulating scoring + goals
class PaccerLib {
    private:
        LiquidCrystal* lcd;
    public:
        PaccerLib(LiquidCrystal* lcd);
        void printProgressively(String str, int delayMillis);
        void printRandomized(String str, int minDelay, int maxDelay);
};

#endif
