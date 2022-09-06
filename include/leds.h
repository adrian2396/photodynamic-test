#ifndef LEDS_H 
#define LEDS_H

#include <Arduino.h>
#include <Wire.h>

#include "parameters.h" 
#include "stepper.h"

/* leds parameters */
struct testParameters{
    float nFrequency;
    float nPower;
    float nDuty;
    float nTime;
};
typedef struct testParameters testParameters;

/* leds variables */
struct ledsVariables{
    testParameters dataRow[MAX_N_ROWS + 1][2];                 // Filas de 1 a 10 y columnas 1 a 2 (A y B)

    bool startTests = false;
    bool stopTests = false;
    bool actualizeOled = false;
    bool actualizeLeds = false;
    bool blink = false;

    int stateLedsGR = L_S_NULL;
    int stateLedsGRBlink = L_S_NULL;
    int actualColumn = ROW1;
    int actualRow = false;
    int changes = DO_NOTHING;
    int ledsWavelength = NM_660;
    int parpadeo = 2;

    int dutyDriverA[16];
    int dutyDriverB[16]; 

    String actualRowS = "";
};
typedef struct ledsVariables ledsVariables;

class leds {
private:
public:
    leds();
    ~leds();

    /* variables */
    ledsVariables ledsVar;

    stepperMotor *stepperLeds;
    
    /* functions */
    void vStartTests();
    void vSaveTimes();
    void vActualizeGRLeds();
    void vRGBlink();
    void vPrintlnData(int actualRow);

    void vPwmColumnA(float power, float duty, int frequency);
    void vPwmColumnB(float power, float duty, int frequency);
    void vPwmColumnAoff();
    void vPwmColumnBoff();

    void vDutys();
    void vInicializeData();
};

#endif
