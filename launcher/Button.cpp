/*
* Button.cpp - library for reading button status.
* created by V. Raška, July 23, 2019.
* Released into the General Public License v3.0.
*/

#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, bool pullup, int timeout) {
  if(pullup) {
    pinMode(pin, INPUT_PULLUP);
  }
  else {
    pinMode(pin, INPUT);
  }

  _pin = pin;
  _timeout = timeout;
}

bool Button::pushed() {
  if(millis()-lastRead >= _timeout) {
    if(digitalRead(_pin) == 1) {
      lastRead = millis();
      return true;
    }
    else return false;
  }
  else return false;
}

long Button::held() {
  if(millis()-lastRead >= _timeout) {
    if(digitalRead(_pin) == 1) {
      heldTime = millis();
      while(digitalRead(_pin) == 1) {
        ;
      }
      return millis()-heldTime;
    }
    else return 0;
  }
  else return 0;
}
