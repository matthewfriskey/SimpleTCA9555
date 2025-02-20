#include <Arduino.h>
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);

// Named input wrappers
inline bool reed_switch() { return expander.input_1(); }
inline bool door_sensor() { return expander.input_2(); }
inline bool button()      { return expander.input_3(); }
inline bool motion()      { return expander.input_9(); }
inline bool window()      { return expander.input_13(); }
inline bool alarm()       { return expander.input_16(); }

void setup() {
    Serial.begin(115200);
    expander.begin(21, 22, 23); // SDA=21, SCL=22, INT=23 (adjust as needed)
}

void loop() {
  if (reed_switch()) {
    Serial.println("Reed switch is HIGH");
  }
  if (!door_sensor()) {
    Serial.println("Door sensor is LOW");
  }
  if (button()) {
    Serial.println("Button is pressed");
  }
  if (motion()) {
    Serial.println("Motion detected");
  }
  if (window()) {
    Serial.println("Window is open");
  }
  if (alarm()) {
    Serial.println("Alarm triggered");
  }
  delay(500);
}