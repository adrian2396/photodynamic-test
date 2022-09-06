#ifndef OLED_H 
#define OLED_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#include "parameters.h"
#include "leds.h"
#include "stepper.h"

struct oledVaraibles{
    int posY[6];
    int posX[6];
    String sOledNameSection[5];
    String sRows[MAX_N_ROWS + 1];
    String Column = "";

    int oledMessages = DO_NOTHING;
    int number = DO_NOTHING;
};
typedef struct oledVaraibles oledVaraibles;

class oled{
private:
    /* data */
public:
    oled(leds *ledsOled_, stepperMotor *stepper_);
    ~oled();

    oledVaraibles oledVar;
    
    leds *ledsOled;
    stepperMotor *stepper;
    
    void vOldedValues();
    void vShowData(int actualRow, int column);
    void displayMessages(int message);
    void displayAP(String ip_address, String name, String password);
    void vActualizeChanges();
};

#endif