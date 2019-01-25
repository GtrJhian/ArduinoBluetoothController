#include <Arduino.h>
#include "Encoder.h"


Encoder::Encoder(uint8_t pinA, uint8_t pinB, uint8_t pinC){
  _A=Switch(pinA);
  _B=Switch(pinB);
  _C=Switch(pinC);
}

void Encoder::begin(){
    _A.begin();
    _B.begin();
    _C.begin(0,INPUT,1);
}

void Encoder::begin(uint8_t debounceTime){
    _A.begin(debounceTime);
    _B.begin(debounceTime);
    _C.begin(debounceTime,INPUT,1);
}

void Encoder::begin(uint8_t debounceTime,uint8_t switchDebounceTime){
  _A.begin(debounceTime);
  _B.begin(debounceTime);
  _C.begin(switchDebounceTime,INPUT,1);
  _timer=millis();
}

int8_t Encoder::getRotation(){
  if(_A.read()&&_B.read()){
    if(_direction==1||(_direction=0)>1){
      return 1;
    }
    return -1;
  }
  if(_direction!=0) return 0;
  if(!_A.read()){
    _direction=1;
    return 0;
  }
  if(!_B.read()){
    _direction=2;
  }
  return 0;
}
uint8_t Encoder::getButton(){
  return _C.read();
}