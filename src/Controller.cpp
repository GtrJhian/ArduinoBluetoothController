#include "Controller.h"
#include "Arduino.h"
#define ENCODER_DEBOUNCE (millis()-_timer>=_debounceTime)
#define ENCODER_SWITCH_DEBOUNCE (millis()-_timer>=_switchDebounceTime)


Controller::Controller(byte fireButton, byte reloadButton, byte motor, byte encoderPinA, byte encoderPinB, byte encoderPinC){
  _fireButton==fireButton;
  _reloadButton=reloadButton;
  _motor=motor;
  //Encoder temp(encoderPinA,encoderPinB,encoderPinC);
  _encoder=Encoder(encoderPinA,encoderPinB,encoderPinC);
}

void Controller::begin(){
  pinMode(_fireButton,INPUT_PULLUP);
  pinMode(_reloadButton,INPUT_PULLUP);
  pinMode(_motor,OUTPUT);
  _encoder.begin();
}
void Controller::begin(unsigned int switchDebounceTime,unsigned int encoderDebounceTime){
  
}

Controller::Encoder::Encoder(byte pinA, byte pinB, byte pinC){
  _pinA=pinA;
  _pinB=pinB;
  _pinC=pinC;
}
void Controller::Encoder::begin(){
  pinMode(_pinA,INPUT);
  pinMode(_pinB,INPUT);
  pinMode(_pinC,INPUT);
}
void Controller::Encoder::begin(int debounceTime,int switchDebounceTime){
  _debounceTime=debounceTime;
  _switchDebounceTime=switchDebounceTime;
  begin();
  _timer=millis();
}
int Controller::Encoder::getRotation(){
  if(digitalRead(_pinA)&&digitalRead(_pinB)){
    if(_direction==1||(_direction=0)>1){
      return 1;
    }
    return -1;
  }
  if(_direction!=0) return 0;
  if(!digitalRead(_pinA)&&ENCODER_DEBOUNCE){
    _timer=millis();
    _direction=1;
  }
  if(!digitalRead(_pinB)&&ENCODER_DEBOUNCE){
    _timer=millis();
    _direction=2;
  }
  return 0;
}
byte Controller::Encoder::getButton(){
  if(ENCODER_SWITCH_DEBOUNCE){
    _timer=millis();
    buttonReading=digitalRead(_pinC);
  }
  return buttonReading;
}
