/*
 * Segment.h - library for showing digits on sevensegment display.
 * created by V. Raška, July 23, 2019.
 * Released into the General Public License v3.0.
 * 
 *    __1__
 *   |     |
 *   6     2
 *   |__7__|
 *   |     |
 *   5     3
 *   |__4__|
 *   
 */

#ifndef Segment_h
#define Segment_h

#include "Arduino.h"

class Segment {
  private:
    int pin[7];
    
    bool pin_normal;
    
    byte digitData[11][7] = {
      {1, 1, 1, 1, 1, 1, 0},
      {0, 1, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 1, 0, 0, 1},
      {0, 1, 1, 0, 0, 1, 1},
      {1, 0, 1, 1, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 0, 0, 0},
    };

  public:
    Segment(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, bool normal=false);
    void write(int number);
    void clear();
    
};

#endif
