#ifndef ENCODER_H
#define ENCODER_H
#include <Arduino.h>
#include "Switch.h"

class Encoder {
      public:
        Encoder(){}
        Encoder(uint8_t pinA, uint8_t pinB, uint8_t pinC);
        void begin();
        void begin(uint8_t debounceTime);
        void begin(uint8_t encoderDebounceTime,uint8_t switchDebounceTime);
        int8_t getRotation();
        uint8_t getButton();
      private:
        Switch _A;
        Switch _B;
        Switch _C;
        uint8_t _direction;
        uint64_t _timer;
};

#endif