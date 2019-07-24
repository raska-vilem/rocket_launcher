/*
 * launcher is software optimalized for ATmega8 in rocket engine lighter
 * 
 * created by V. Raška, July 23, 2019.
 * Released into the General Public License v3.0.
 */



#include "Button.h"
#include "Buzzer.h"
#include "Segment.h"

//pin definitions
//segment display A
#define A_1 7
#define A_2 5
#define A_3 9
#define A_4 11
#define A_5 10
#define A_6 6
#define A_7 8

//segment display B
#define B_1 4
#define B_2 21
#define B_3 2
#define B_4 0
#define B_5 1
#define B_6 20
#define B_7 3

//ignition relay
#define pin_starter 12

//audio countdown buzzer
#define pin_buzzer 13

//control buttons
#define pin_button_red A4
#define pin_button_blue A3

//potentiometer
#define pin_potentiometer A5

//battery detect
#define pin_battery A2

Segment segA(A_1, A_2, A_3, A_4, A_5, A_6, A_7, true);
Segment segB(B_1, B_2, B_3, B_4, B_5, B_6, B_7, true);

Button buttonRed(pin_button_red, true, 500);
Button buttonBlue(pin_button_blue, true, 500);

Buzzer buzzer(pin_buzzer);

void setup() {
  buzzer.start_buzz();

  pinMode(pin_battery, INPUT);
  pinMode(pin_potentiometer, INPUT);
}

void loop() {
  
}

void writeNumber(int number) {
  segB.write(number % 10);
  if(number < 10) {
    segA.clear();
  }
  else {
    segA.write(number/10 % 10);
  }
}
