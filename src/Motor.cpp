#include "Motor.h"

Motor::Motor(uint8_t pin){
    _pin=pin;
}
void Motor::begin(){
    pinMode(_pin,OUTPUT);
    digitalWrite(_pin,LOW);
}
void Motor::run(){
    digitalWrite(_pin,HIGH);
    _isWatching=0;
}
void Motor::run(uint16_t time){
    digitalWrite(_pin,HIGH);
    _isWatching=1;
    _timer=millis();
    _time=time;
}
void Motor::stop(){
    digitalWrite(_pin,LOW);
    _isWatching=0;
}
void Motor::watch(){
    if(_isWatching&&millis()-_timer>=_time){
        digitalWrite(_pin,LOW);
    }
}