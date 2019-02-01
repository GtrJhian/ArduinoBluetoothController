#ifndef Controller_h
#define Controller_h
#include "Arduino.h"
#include "Encoder.h"
#include "Motor.h"
class Controller {
  public:
    Controller(uint8_t fireButton, uint8_t reloadButton, uint8_t boltButton, uint8_t motor, uint8_t encoderPinA, uint8_t encoderPinB, uint8_t encoderPinC);
    uint8_t getControllerData();
    void begin();
    void begin(uint16_t, uint16_t);
    void vibrate(uint16_t time);
    void vibrate();
    void stopVibrating();
  private:
    Switch _fireButton;
    Switch _reloadButton;
    Switch _boltButton;
    Encoder _encoder;
    Motor _motor;
};

#endif
