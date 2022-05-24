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

void PaccerCommon::addScore(const uint32_t &amount) {
    setScore(max(_score + amount, 0));
}

void PaccerCommon::setScore(const uint32_t &amount) {
    output->updateScore(amount);
    _score = amount;
}

void PaccerCommon::resetScore() {
    setScore(0);
}

void PaccerCommon::input(const unsigned int& type) {
    switch (type) {
        case INPUT_SPRING_START:
            resetScore();
            broadcast("UR BAD");
            break;
        case INPUT_PACMAN_START:
            break;
        case INPUT_SENSOR_3:
            addScore(1000);
            broadcast("NICE");
            break;
        case INPUT_SENSOR_4:
            addScore(5000);
            break;
        case INPUT_SENSOR_5:
            addScore(1000000000);
            break;
        case INPUT_PACMAN_INSIDE:
            addScore(100);
            break;
        default:
            serial("Unknown input type " + String(type));
    }
}

void PaccerCommon::broadcast(const String &msg) {
    output->broadcast(msg);
}

void PaccerCommon::tick() {

}

void PaccerCommon::serial(const String &msg) {
    Serial.println( "COMMON | " + msg);
}