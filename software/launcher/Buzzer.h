/*
 * Buzzer.h - library for buzzer.
 * created by V. Raška, July 23, 2019.
 * Released into the General Public License v3.0.
 */

#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer {
  public:
    Buzzer(int pin);
    void buzz(int time);
    void start_buzz();
    void stop_buzz();

  private:
    int _pin;
};

#endif
