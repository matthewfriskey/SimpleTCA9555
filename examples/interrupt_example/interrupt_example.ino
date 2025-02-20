#include <Arduino.h>
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);

// Named input aliases
#define reed_switch expander.input_1
#define door_sensor expander.input_2
#define button      expander.input_3
#define motion      expander.input_9
#define window      expander.input_13
#define alarm       expander.input_16

void setup() {
  Serial.begin(115200);
  expander.begin(21, 22, 23); // SDA=21, SCL=22, INT=23
}

void loop() {
  if (reed_switch) {
    Serial.println("Reed switch is HIGH");
  }
  if (!door_sensor) {
    Serial.println("Door sensor is LOW");
  }
  if (button) {
    Serial.println("Button is pressed");
  }
  if (motion) {
    Serial.println("Motion detected");
  }
  if (window) {
    Serial.println("Window is open");
  }
  if (alarm) {
    Serial.println("Alarm triggered");
  }
  delay(500);
}