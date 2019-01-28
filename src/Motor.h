#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

class Motor{
    public:
        Motor(){}
        Motor(uint8_t pin);
        void begin();
        void run();
        void run(uint16_t time);
        void stop();
        void stop(uint16_t time);
        void watch();
    private:
        uint8_t _pin;
        uint8_t _isWatching;
        uint16_t _time;
        uint64_t _timer;
        
};


#endif