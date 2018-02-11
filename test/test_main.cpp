/**
 *  @file     test_main.cpp
 *  @version  0.1.0
 *  @date     2018-02-11
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@nhuvo.ch>
 *  @brief    Blinking built-in led
 */

#ifdef UNIT_TEST

#include <Arduino.h>
#include <unity.h>

unsigned char status = 0;

void test_pin_builtin(void);

void test_led_low(void);

void test_led_high(void);

void setup() {
  delay(2000);
}

void loop() {
  switch(status) {

    // Start unity test
    case 0:
      UNITY_BEGIN();
      status++;
      break;

    // Test LED Pin built-in
    case 1:
      RUN_TEST(test_pin_builtin);
      delay(500);
      status++;
      break;

    // Set pin mode
    case 2:
      pinMode(LED_BUILTIN, OUTPUT);
      status++;
      break;

    // Set led pin low
    case 3:
      digitalWrite(LED_BUILTIN, LOW);
      status++;
      break;

    // Test led is low
    case 4:
      RUN_TEST(test_led_low);
      delay(500);
      status++;
      break;

    // Set led pin high
    case 5:
      digitalWrite(LED_BUILTIN, HIGH);
      status++;
      break;

    // Test led is low
    case 6:
      RUN_TEST(test_led_high);
      delay(500);
      status++;
      break;

    default:
      UNITY_END();
  }
}

void test_pin_builtin(void) {
  TEST_ASSERT_EQUAL(LED_BUILTIN, 16);
}

void test_led_low(void) {
  TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
}

void test_led_high(void) {
  TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
}

#endif
