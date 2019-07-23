/*
 * Segment.cpp - library for showing digits on sevensegment display.
 * created by V. Raška, July 23, 2019.
 * Released into the General Public License v3.0.
 */

#include "Arduino.h"
#include "Segment.h"

Segment::Segment(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, bool normal) {
  pin[0] = pin0;
  pin[1] = pin1;
  pin[2] = pin2;
  pin[3] = pin3;
  pin[4] = pin4;
  pin[5] = pin5;
  pin[6] = pin6;

  pin_normal = normal;

  for(int i=0; i<7; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], pin_normal);
  }
}

void Segment::write(int number) {
  if(pin_normal) {
    for(int i=0; i<7; i++) {
      digitalWrite(pin[i], !digitData[number][i]);
    }
  }
  
  else {
    for(int i=0; i<7; i++) {
      digitalWrite(pin[i], digitData[number][i]);
    }
  }
}

void Segment::clear() {
  if(pin_normal) {
    for(int i=0; i<7; i++) {
      digitalWrite(pin[i], !digitData[10][i]);
    }
  }
  else {
    for(int i=0; i<7; i++) {
      digitalWrite(pin[i], digitData[10][i]);
    }
  }
}
