#include <Arduino.h>
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);

// Named input aliases
#define reed_switch expander.input_1
#define door_sensor expander.input_2
#define button      expander.input_3

void setup() {
    Serial.begin(115200);
    expander.begin(21, 22); // SDA=21, SCL=22 (adjust as needed)
}

void loop() {
    expander.update(); // Refresh input states

  if (reed_switch) {
    Serial.println("Reed switch is HIGH");
  }
  if (!door_sensor) {
    Serial.println("Door sensor is LOW");
  }
  if (button) {
    Serial.println("Button is pressed");
  }
    delay(500);
}