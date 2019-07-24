/*
* Button.h - library for reading button status.
* created by V. Raška, July 23, 2019.
* Released into the General Public License v3.0.
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
  private:
    int _pin;
    bool _pullup;
    unsigned long long lastRead = 0;
    unsigned long long heldTime = 0;
    int _timeout;

  public:
    Button(int pin, bool pullup=false, int timeout=200);
    bool pushed();
    long held();
};

#endif
