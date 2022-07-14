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
            broadcast("GAMEOVER");
            output->led(LED_OFF);
            output->sound(SOUND_PLONG);
            break;
        case INPUT_PACMAN_INSIDE:
            addScore(1000);
            broadcast("NICE JOB");
            output->sound(SOUND_PLING);
            output->led(LED_PACMAN);
            break;
        case INPUT_HOLE_ONE:
            addScore(200);
            output->servo();
            break;
        case INPUT_HOLE_TWO:
            // TODO impl
            addScore(300);
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