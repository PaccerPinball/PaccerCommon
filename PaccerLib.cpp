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


#include "PaccerLib.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

PaccerLib::PaccerLib(LiquidCrystal* lcd) {
    this->lcd = lcd;
}

void PaccerLib::printProgressively(String str, int delayMillis) {
    for (int i = 0; i < str.length(); i++) {
        lcd->write(str[i]);
        delay(delayMillis);
    }
}

void PaccerLib::printRandomized(String str, int minDelay, int maxDelay) {
    for (int i = 0; i < str.length(); i++) {
        lcd->write(str[i]);
        int delayMillis = rand() % (maxDelay-minDelay+1) + minDelay;
        Serial.print("Delay: ");
        Serial.println(delayMillis);
        delay(delayMillis);
    }
}
