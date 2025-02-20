#include <Arduino.h>
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);

// Named input wrappers
inline bool reed_switch() { return expander.input_1(); }
inline bool door_sensor() { return expander.input_2(); }
inline bool button()      { return expander.input_3(); }

void setup() {
    Serial.begin(115200);
    expander.begin(21, 22); // SDA=21, SCL=22 (adjust as needed)
}

void loop() {
    expander.update(); // Refresh input states

    if (reed_switch()) {
        Serial.println("Reed switch is HIGH");
    }
    if (!door_sensor()) {
        Serial.println("Door sensor is LOW");
    }
    if (button()) {
        Serial.println("Button is pressed");
    }
    if (expander.input_9()) {
        Serial.println("Motion detected");
    }
    if (expander.input_13()) {
        Serial.println("Window is open");
    }
    if (expander.input_16()) { // Alarm
        Serial.println("Alarm triggered");
    }
    delay(500);
}