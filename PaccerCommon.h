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
#include <PaccerOutput.h>

// Inputs - at the same time the pin numbers
#define INPUT_SPRING_START 3
#define INPUT_PACMAN_INSIDE 4
#define INPUT_SLOW_PROPELLOR 8
#define INPUT_HOLE_ONE 10
#define INPUT_HOLE_TWO 11

class PaccerCommon {
    private:
        uint32_t _score{};
        PaccerOutput* output;
        uint16_t servoTime{};
        /*void printProgressively(const String& str, int delayMillis);
        void printRandomized(const String& str, int minDelay, int maxDelay);*/
        void addScore(const uint32_t &amount);
        void setScore(const uint32_t &amount);
        void resetScore();
        /**
         * Send a message to PaccerOutput.
         * This will e.g. get displayed on the LCD.
         * @param msg the msg to broadcast
         */
        void broadcast(const String& msg);
        static void serial(const String &msg);
    public:
        explicit PaccerCommon(PaccerOutput* output);
        /**
         * Indicate that an input, e.g. a sensor, was "activated".
         * @param type the type of input, e.g. INPUT_SPRING_START
         */
        void input(const unsigned int& type);
        /** Called from the main arduino sketch every loop() */
        void tick();
};

#endif
