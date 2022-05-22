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

#ifndef PaccerCommon_H
#define PaccerCommon_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <PaccerOutput.h>

enum InputType {
    springStart,
    pacmanStart,
    pacmanInside,

};

// TODO LiquidCrystal_I2C support
// TODO functions like score(points), announce(str) for simulating scoring + goals
class PaccerCommon {
    private:
        int _score{};
        PaccerOutput* output;
        /*void printProgressively(const String& str, int delayMillis);
        void printRandomized(const String& str, int minDelay, int maxDelay);*/
        void addScore(const int& amount);
        void setScore(const int& amount);
        void resetScore();
        /**
         * Send a message to PaccerOutput.
         * This will e.g. get displayed on the LCD.
         * @param msg the msg to broadcast
         */
        void broadcast(const String& msg);
    public:
        explicit PaccerCommon(PaccerOutput* output);
        /**
         * Indicate that an input, e.g. a sensor, was "activated".
         * @param type the type of input, e.g. springStart
         */
        void input(InputType type);
        /** Called from the main arduino sketch every loop() */
        void tick();
};

#endif
