#include <Arduino.h>
#include "Controller.h"
#include "Constants.h"

Controller controller(FIRE_BUTTON_PIN,RELOAD_BUTTON_PIN,MOTOR_PIN,ENCODER_PIN_A,ENCODER_PIN_B,ENCODER_PIN_C);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BLUETOOTH_BAUDRATE);
  controller.begin(ENCODER_DEBOUNCE_MILLIS,SWITCH_DEBOUNCE_MILLIS);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(controller.getControllerData());
}
