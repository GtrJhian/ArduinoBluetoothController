#include "Controller.h"
#include "Arduino.h"


Controller::Controller(uint8_t fireButton, uint8_t reloadButton, uint8_t motor, uint8_t encoderPinA, uint8_t encoderPinB, uint8_t encoderPinC){
  _fireButton=Switch(fireButton);
  _reloadButton=Switch(reloadButton);
  _motor=motor;
  _encoder=Encoder(encoderPinA,encoderPinB,encoderPinC);
}

void Controller::begin(){
  _fireButton.begin(0,INPUT_PULLUP);
  _reloadButton.begin(0,INPUT_PULLUP,1);
  _encoder.begin();
  pinMode(_motor,OUTPUT);
  
}
void Controller::begin(uint16_t encoderDebounceTime,uint16_t switchDebounceTime){
  _fireButton.begin(switchDebounceTime,INPUT_PULLUP);
  _reloadButton.begin(switchDebounceTime,INPUT_PULLUP,1);
  _encoder.begin(encoderDebounceTime,switchDebounceTime);
  pinMode(_motor,OUTPUT);
}

/*
  Controller Data Format
  bit 0 - FireButton
  bit 1 - ReloadButton
  bit 2 - Encoder BUTTON
  bit 3 - Encoder CW
  bit 4 - Encoder CCW 
*/
uint8_t Controller::getControllerData(){
  uint8_t data=0x00;
  data|=_fireButton.read();
  data|=_reloadButton.read()<<1;
  data|=_encoder.getButton()<<2;
  int8_t temp=_encoder.getRotation();
  data|=temp==0?data:temp>0?1<<3:1<<4;
  return data;
}

void Controller::setVibration(uint8_t state){
  digitalWrite(_motor,state>0?1:0);
}
