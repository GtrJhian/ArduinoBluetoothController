#include <Arduino.h>
#include "Switch.h"

Switch::Switch(uint8_t pin){
    _pin=pin;
}
void Switch::begin(){
    pinMode(_pin,INPUT);
}
void Switch::begin(uint8_t bounceTime){
    _bounceTime=bounceTime;
    pinMode(_pin,INPUT);
}
void Switch::begin(uint8_t bounceTime, uint8_t inputType){
    _bounceTime=bounceTime;
    pinMode(_pin,inputType);
}
void Switch::begin(uint8_t bounceTime, uint8_t inputType, uint8_t invertLogic){
    _bounceTime=bounceTime;
    pinMode(_pin,inputType);
    _invertLogic=_invertLogic>0?1:0;
}

uint8_t Switch::read(){
    if(digitalRead(_pin)!=_state&&millis()-_bounceTimer>=_bounceTime){
        _state=!_state;
        _bounceTimer=millis();
    }
    return _invertLogic?!_state:_state;
}