#include "stepper.h"

extern hw_timer_t * timer;

extern int interrupt;
extern int blink;
extern int blinkLed;

void stepperMotor::vOneStep(){ 
    digitalWrite(STEP, HIGH);         
    delayMicroseconds(5);              
    digitalWrite(STEP, LOW);       
    delayMicroseconds(500);
}

void stepperMotor::vMoveStepper(int steps, int direction){
  int i = 0;
  digitalWrite(EN, LOW); 
  digitalWrite(DIR, direction);
  timerAlarmEnable(timer);
  interrupt = BLINK;
  blinkLed = RED;
  while(i < steps){
        vOneStep();
        i++;
  }
  digitalWrite(EN, HIGH);
  timerAlarmDisable(timer);
}

void stepperMotor::vCalibrateStepper(int steps, int direction){
  int i = 0;
  digitalWrite(EN, LOW); 
  digitalWrite(DIR, false);
  timerAlarmEnable(timer);
  interrupt = BLINK;
  blinkLed = RED;
  while(digitalRead(FC) == false && i < steps){
        vOneStep();
        i++;
  }
  digitalWrite(EN, HIGH);
  timerAlarmDisable(timer);
}