#include <Arduino.h>
#include "Controller.h"
#include "Constants.h"
#include <SoftwareSerial.h>

Controller controller(FIRE_BUTTON_PIN,RELOAD_BUTTON_PIN,BOLT_BUTTON_PIN
,MOTOR_PIN,ENCODER_PIN_A,ENCODER_PIN_B,ENCODER_PIN_C);
SoftwareSerial BT(BLUETOOTH_TX_PIN,BLUETOOTH_RX_PIN);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BLUETOOTH_BAUDRATE);
  BT.begin(BLUETOOTH_BAUDRATE);
  controller.begin(ENCODER_DEBOUNCE_MILLIS,SWITCH_DEBOUNCE_MILLIS);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if(Serial.available()){
    uint8_t c;
    while((c=Serial.read())!=10){
      BT.write(c);
      //Serial.print(c);
    }
  }
  while(BT.available()){
    Serial.println(BT.read(),BIN);
  }
  */
  Serial.write(controller.getControllerData());
  if(Serial.available()){
    if(Serial.read()==MOTOR_VIBRATE_BYTE)
    controller.vibrate(MOTOR_VIBRATE_TIME);
  }
}
