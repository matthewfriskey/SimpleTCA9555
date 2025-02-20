#include <Arduino.h>
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);

#define reed_switch input_1   // P00
#define door_sensor input_2   // P01
#define button      input_3   // P02
#define motion      input_9   // P10
#define window      input_13  // P14
#define alarm       input_16  // P17

void setup() {
    Serial.begin(115200);
    // SDA=21, SCL=22, INT=23, 400 kHz clock speed
    expander.begin(21, 22, 23, 400000);
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