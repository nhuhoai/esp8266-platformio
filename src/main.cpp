/**
 *  @file     main.cpp
 *  @version  0.1.0
 *  @date     2018-02-11
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@nhuvo.ch>
 *  @brief    Blinking built-in led
 */

#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
