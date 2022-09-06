#ifndef STATION_H 
#define STATION_H

#include <ESPAsyncWebServer.h>
#include <AsyncJson.h>
#include <ArduinoJson.h>

#include "parameters.h"
#include "webPage.h"
#include "oled.h"
#include "stepper.h"


struct stationVariables{
    String columnLetter = "A";

    int rowNumber = ROW1;
    int column = false;
    int wavelenght = false;
    int clickOn = -1;

};
typedef struct stationVariables stationVariables;


class stationMode{
private:
    int iGetRowNumber(String path);
    String iGetRowLetter(String path);
    static void vAsyncHandleNotFound(AsyncWebServerRequest *request);
public:
    stationMode(oled *displayStation_, stepperMotor *stepper_);
    ~stationMode();

    stationVariables stationVar;
    
    AsyncWebServer *asyncServer;
    oled *displayStation;
    stepperMotor *stepper;

    void runAsStation();
    void vActualiceDataWeb();
};

#endif