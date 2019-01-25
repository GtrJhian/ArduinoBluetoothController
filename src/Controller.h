#ifndef Controller_h
#define Controller_h
#include "Arduino.h"
#include "Encoder.h"
class Controller {
  public:
    Controller(uint8_t fireButton, uint8_t reloadButton, uint8_t motor, uint8_t encoderPinA, uint8_t encoderPinB, uint8_t encoderPinC);
    uint8_t getControllerData();
    void setVibration(uint8_t state);
    void begin();
    void begin(uint16_t, uint16_t);
  private:
    Switch _fireButton;
    Switch _reloadButton;
    Encoder _encoder;
    uint8_t _motor;
};

#endif
