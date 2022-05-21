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
#include <HardwareSerial.h>

PaccerLib::PaccerLib(LiquidCrystal* lcd) {
    this->lcd = lcd;
}

void PaccerLib::printProgressively(const String& str, int delayMillis) {
    for (char i : str) {
        lcd->write(i);
        delay(delayMillis);
    }
}

void PaccerLib::printRandomized(const String& str, int minDelay, int maxDelay) {
    for (char i : str) {
        lcd->write(i);
        int delayMillis = rand() % (maxDelay-minDelay+1) + minDelay;
        Serial.print("Delay: ");
        Serial.println(delayMillis);
        delay(delayMillis);
    }
}

#pragma clang diagnostic pop