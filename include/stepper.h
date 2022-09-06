#ifndef STEPPER_H 
#define STEPPER_H

#include <Arduino.h>
#include "parameters.h"

#define EN  13
#define STEP 14
#define DIR 27
#define FC 32

struct stepperVaraibles{
    bool fc = false;
    bool moveStepper = false;
    bool direction = false;

    int nSteps = false;
    int rows = ROW1;
};
typedef struct stepperVaraibles stepperVaraibles;

class stepperMotor{
public:

    stepperVaraibles stepperMotorVar;
    
    void vOneStep();
    void vMoveStepper(int steps, int direction);
    void vCalibrateStepper(int steps, int direction);
};

#endif