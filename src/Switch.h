#ifndef SWITCH_H
#define SWITCH_H
    #include "Arduino.h"
    class Switch{
        public:
            Switch(){}
            Switch(uint8_t);
            void begin();
            void begin(uint8_t);
            void begin(uint8_t, uint8_t);
            void begin(uint8_t, uint8_t, uint8_t);
            uint8_t read();
        private:
            uint8_t _pin;
            uint8_t _state=0;
            uint8_t _bounceTime;
            uint8_t _invertLogic=0;
            uint64_t _bounceTimer=0;
    };
#endif