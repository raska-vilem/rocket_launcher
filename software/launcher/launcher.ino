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

//battery voltage detect
#define pin_battery A2

//battery indicaion LEDs
#define pin_led_1 A0
#define pin_led_2 A1

//time definitions
#define max_countdown_time 30   //seconds
#define max_ignition_time 50    //tenth of second
#define countdown_beep_time 100 //milliseconds
#define blink_speed 600         //milliseconds
#define blink_delay 500         //milliseconds



Segment segA(A_1, A_2, A_3, A_4, A_5, A_6, A_7, true);
Segment segB(B_1, B_2, B_3, B_4, B_5, B_6, B_7, true);

Button buttonRed(pin_button_red, true, 500);
Button buttonBlue(pin_button_blue, true, 500);

Buzzer buzzer(pin_buzzer);


int countdown_time;
int ignition_time;
bool state = false;

void setup() {
  pinMode(pin_battery, INPUT);
  pinMode(pin_potentiometer, INPUT);
  pinMode(pin_led_1, OUTPUT);
  pinMode(pin_led_2, OUTPUT);
  pinMode(pin_starter, OUTPUT);


  segA.write(16);
  segB.write(16);
  
  buzzer.buzz(100);
  
  segA.clear();
  segB.clear();
  
  wait(100);
  
  segA.write(16);
  segB.write(16);
  
  buzzer.buzz(150);
  
  segA.clear();
  segB.clear();

  wait(750);
  
  timeSettings();
}

void loop() {
  if(buttonBlue.pushed()) {
    buzzer.buzz(150);
    timeSettings();
  }

  
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

void countDown(int time) {
  
}

bool wait(int time) {
  unsigned long long timePoint = millis();

  while(millis() - timePoint <= time) {
    ;
  }
  return true;
}

int setCountdownTime() {
  segA.write(12);
  segB.clear();
  wait(750);
  
  int countdown;
  int countdown_last;
  unsigned long long timePoint = millis();
  unsigned long long timePoint_blink_delay = millis();
  bool state = true;
  
  while(!buttonBlue.pushed()) {
    countdown = map(analogRead(pin_potentiometer), 1023, 0, 0, max_countdown_time+1);

    if(countdown == countdown_last) {
      if(millis() - timePoint_blink_delay >= blink_delay) {
        if(millis() - timePoint >= blink_speed) {
          timePoint = millis();
          
          if(state) {
            writeNumber(countdown);
            state = !state;
          }
          
          else {
            segA.clear();
            segB.clear();
            state = !state;
          }
        }
      }
    }
    else {
      writeNumber(countdown);
      countdown_last = countdown;
      timePoint_blink_delay = millis();
    }
  }

  buzzer.buzz(75);

  return countdown;
}

int setIgnitionTime() {
  segA.write(11);
  segB.clear();
  wait(750);
  
  int ignition;
  int ignition_last;
  unsigned long long timePoint = millis();
  unsigned long long timePoint_blink_delay = millis();
  bool state = true;
  
  while(!buttonBlue.pushed()) {
    ignition = map(analogRead(pin_potentiometer), 1023, 0, 0, max_ignition_time+1);

    if(ignition == ignition_last) {
      if(millis() - timePoint_blink_delay >= blink_delay) {
        if(millis() - timePoint >= blink_speed) {
          timePoint = millis();
          
          if(state) {
            writeNumber(ignition);
            state = !state;
          }
          
          else {
            segA.clear();
            segB.clear();
            state = !state;
          }
        }
      }
    }
    else {
      writeNumber(ignition);
      ignition_last = ignition;
      timePoint_blink_delay = millis();
    }
  }

  buzzer.buzz(75);

  return ignition;
}

void timeSettings() {
  countdown_time = setCountdownTime();
  ignition_time = setIgnitionTime();

  segA.clear();
  segB.clear();
}
