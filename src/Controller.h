#ifndef Controller_h
#define Controller_h
#include "Arduino.h"
class Controller {
  public:
    Controller(byte fireButton, byte reloadButton, byte motor, byte encoderPinA, byte encoderPinB, byte encoderPinC);
    byte getControllerData();
    void setVibration(byte state);
    void begin();
    void begin(unsigned int, unsigned int);
  private:
    class Encoder {
      public:
        Encoder();
        Encoder(byte pinA, byte pinB, byte pinC);
        void begin();
        void begin(int debounceTime,int switchDebounceTime);
        int getRotation();
        byte getButton();
      private:
        byte _pinA;
        byte _pinB;
        byte _pinC;
        byte buttonReading;
        unsigned int _debounceTime;
        unsigned int _switchDebounceTime;
        byte _direction;
        unsigned long long _timer;
    };
    byte _fireButton;
    byte _reloadButton;
    byte _motor;
    unsigned int _switchDebounceTime;
    Encoder _encoder;
};

#endif
