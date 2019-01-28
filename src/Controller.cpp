#include "Controller.h"
#include "Arduino.h"


Controller::Controller(uint8_t fireButton, 
                       uint8_t reloadButton,
                       uint8_t boltButton, 
                       uint8_t motor, 
                       uint8_t encoderPinA, 
                       uint8_t encoderPinB, 
                       uint8_t encoderPinC){                         
  _fireButton=Switch(fireButton);
  _reloadButton=Switch(reloadButton);
  _boltButton=Switch(boltButton);
  _motor=Motor(motor);
  _encoder=Encoder(encoderPinA,encoderPinB,encoderPinC);
}

void Controller::begin(){
  _fireButton.begin(0,INPUT_PULLUP,1);
  _reloadButton.begin(0,INPUT_PULLUP,1);
  _boltButton.begin(0,INPUT_PULLUP,1);
  _encoder.begin();
  _motor.begin();
  
}
void Controller::begin(uint16_t encoderDebounceTime,uint16_t switchDebounceTime){
  _fireButton.begin(switchDebounceTime,INPUT_PULLUP,1);
  _reloadButton.begin(switchDebounceTime,INPUT_PULLUP,1);
  _boltButton.begin(switchDebounceTime,INPUT_PULLUP,1);
  _encoder.begin(encoderDebounceTime,switchDebounceTime);
  _motor.begin();
}

/*
  Controller Data Format
  bit 0 - FireButton
  bit 1 - ReloadButton
  bit 2 - BoltButton
  bit 3 - Encoder BUTTON
  bit 4 - Encoder CW
  bit 5 - Encoder CCW 
*/
uint8_t Controller::getControllerData(){
  uint8_t data=0x00;
  data|=_fireButton.read();
  data|=_reloadButton.read()<<1;
  data|=_boltButton.read()<<2;
  data|=_encoder.getButton()<<3;
  int8_t temp=_encoder.getRotation();
  data|=temp==0?0:temp>0?1<<4:1<<5;
  _motor.watch();
  return data;
}

