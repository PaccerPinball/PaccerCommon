/*
 * PaccerCommon
 * =========
 * 
 * Library for the common code for the Paccer Pinball.
 * -> managing states, score mechanics, etc.
 *
 * This library gets inputs from PaccerInput and sends them to PaccerOutput.
 *
 * Created 2022-05-20
 * 
 * https://github.com/PaccerPinball/PaccerCommon
 */


#include "PaccerCommon.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <PaccerOutput.h>

PaccerCommon::PaccerCommon(PaccerOutput* output) {
    this->output = output;
}

/*void PaccerCommon::printProgressively(const String& str, int delayMillis) {
    for (char i : str) {
        output->write(i);
        delay(delayMillis);
    }
}

void PaccerCommon::printRandomized(const String& str, int minDelay, int maxDelay) {
    for (char i : str) {
        output->write(i);
        int delayMillis = rand() % (maxDelay-minDelay+1) + minDelay;
        Serial.print("Delay: ");
        Serial.println(delayMillis);
        delay(delayMillis);
    }
}*/

void PaccerCommon::addScore(const int &amount) {
    setScore(max(_score + amount, 0));
}

void PaccerCommon::setScore(const int &amount) {
    output->updateScore(amount);
    _score = amount;
}

void PaccerCommon::resetScore() {
    setScore(0);
}

void PaccerCommon::input(InputType type) {
    switch (type) {
        case springStart:
            broadcast("UR BAD");
            break;
        case pacmanStart:
            break;
        case pacmanInside:
            addScore(100);
            break;
    }
}

void PaccerCommon::broadcast(const String &msg) {
    output->broadcast(msg);
}
