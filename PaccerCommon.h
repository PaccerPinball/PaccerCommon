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

// Inputs
#define INPUT_SPRING_START 0
#define INPUT_PACMAN_START 1
#define INPUT_PACMAN_INSIDE 2
#define INPUT_SENSOR_3 3
#define INPUT_SENSOR_4 4
#define INPUT_SENSOR_5 5

// TODO LiquidCrystal_I2C support
class PaccerCommon {
    private:
        uint32_t _score{};
        PaccerOutput* output;
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
