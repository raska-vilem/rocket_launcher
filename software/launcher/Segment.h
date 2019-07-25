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
    
    byte digitData[12][7] = {
      {1, 1, 1, 1, 1, 1, 0},    //0
      {0, 1, 1, 0, 0, 0, 0},    //1
      {1, 1, 0, 1, 1, 0, 1},    //2
      {1, 1, 1, 1, 0, 0, 1},    //3
      {0, 1, 1, 0, 0, 1, 1},    //4
      {1, 0, 1, 1, 0, 1, 1},    //5
      {1, 0, 1, 1, 1, 1, 1},    //6
      {1, 1, 1, 0, 0, 0, 0},    //7
      {1, 1, 1, 1, 1, 1, 1},    //8
      {1, 1, 1, 1, 0, 1, 1},    //9
      {1, 1, 1, 0, 1, 1, 1},    //A
      {0, 0, 1, 1, 1, 1, 1},    //b
      {1, 0, 0, 1, 1, 1, 0},    //C
      {0, 1, 1, 1, 1, 0, 1},    //d
      {1, 0, 0, 1, 1, 1, 1},    //E
      {1, 0, 0, 0, 1, 1, 1},    //F
      {0, 0, 0, 0, 0, 0, 1},    //-
      {0, 0, 0, 0, 0, 0, 0},    //
    };

  public:
    Segment(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, bool normal=false);
    void write(int number);
    void clear();
    
};

#endif
