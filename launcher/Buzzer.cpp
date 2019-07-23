/*
 * Buzzer.cpp - library for buzzer.
 * created by V. Raška, July 23, 2019.
 * Released into the General Public License v3.0.
 */

#include "Arduino.h"
#include "Buzzer.h"


Buzzer::Buzzer(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Buzzer::buzz(int time) {
  long long timeStamp = millis();
  digitalWrite(_pin, HIGH);

  while(millis() - timeStamp < time) {
    ;
  }
  digitalWrite(_pin, LOW);
}

void Buzzer::start_buzz() {
  digitalWrite(_pin, HIGH);
}

void Buzzer::stop_buzz() {
  digitalWrite(_pin, LOW);
}
