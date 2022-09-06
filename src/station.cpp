#include "station.h"

//pthread_mutex_t mutexStation = PTHREAD_MUTEX_INITIALIZER;
extern String active;
extern String column;
extern String power;
extern String frequency;
extern String duty;
extern String timeTest;


extern int allowPass1;
extern int allowPass2;


// --------------------- STATION CLASS METHODS ---------------------//
stationMode::stationMode(oled *displayStation_, stepperMotor *stepper_){
    asyncServer = new AsyncWebServer(80);
    displayStation = displayStation_;
    stepper = stepper_;
    //pthread_mutex_init(&mutexStation, 0);
}
stationMode::~stationMode(){
}

String processor(const String& var){
  //Serial.println(var);
  if(var == "active"){
    return column;
  }
  else if(var == "columnRow"){
    return column;
  }
  else if(var == "power"){
    return power;
  }
  else if(var == "frequency"){
    return frequency;
  }
  else if(var == "duty"){
    return duty;
  }
  else if(var == "timeTest"){
    return timeTest;
  }
  return String();
}

void stationMode::runAsStation(){
    Serial.println("[station.cpp]: web server");
    asyncServer->on("/", HTTP_GET, [this](AsyncWebServerRequest *request) {
      Serial.println("[oledHandle]: serving frontend");
      AsyncWebServerResponse *response; 
      response = request->beginResponse_P(200, "text/html", index_html);
      response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
      response->addHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
      response->addHeader("Access-Control-Allow-Origin","*");
      request->send(response);
      Serial.println("[station.cpp]: frontend served");
    });
    asyncServer->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html, processor);
    });
    asyncServer->on("/active", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", active.c_str());
    });
    asyncServer->on("/columnRow", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", column.c_str());
    });
    asyncServer->on("/power", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", power.c_str());
    });
    asyncServer->on("/frequency", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", frequency.c_str());
    });
    asyncServer->on("/duty", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", duty.c_str());
    });
    asyncServer->on("/timeTest", HTTP_GET, [] (AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", timeTest.c_str());
    });
    asyncServer->onRequestBody([this] (AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {
      Serial.println("[station.cpp]: body request");
      AsyncWebServerResponse *response = NULL; 
      if (request->method() == HTTP_OPTIONS) {
        response = request->beginResponse(200);
      }
      if (request->method() == HTTP_POST) {
        Serial.println("[station.cpp]: POST requets");
        response = request->beginResponse(201);
        const char* body = (const char*) data;
        String path = request->url();
  
        // >>> If button save was pressed (get introduced data)
        if (path.startsWith("/row/")) {
          Serial.println("[station.cpp]: saving row data");
          displayStation->ledsOled->ledsVar.actualColumn = iGetRowNumber(path);
          stationVar.columnLetter = iGetRowLetter(path);

          StaticJsonDocument<256> rowData;
          DeserializationError error = deserializeJson(rowData, body);

          if (error) {
            Serial.print(F("[station.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }
          if(displayStation->ledsOled->ledsVar.startTests == false){
            if (stationVar.columnLetter == "A") {
            displayStation->ledsOled->ledsVar.actualRow = 0;
            Serial.print("Columna: ");
            Serial.println(displayStation->ledsOled->ledsVar.actualColumn);
            Serial.print("Fila: ");
            Serial.println(displayStation->ledsOled->ledsVar.actualRow);
            }
            else if (stationVar.columnLetter == "B") {
              displayStation->ledsOled->ledsVar.actualRow = 1;
              Serial.print("Columna: ");
              Serial.println(displayStation->ledsOled->ledsVar.actualColumn);
              Serial.print("Fila: ");
              Serial.println(displayStation->ledsOled->ledsVar.actualRow);
            }

            displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nFrequency = float(rowData["frequency"]);
            displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nPower = float(rowData["power"]);
            displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nDuty = float(rowData["duty"]);
            displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nTime = float(rowData["time"]);  

            Serial.println(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nFrequency);
            Serial.println(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nTime);
            Serial.println(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nPower);
            Serial.println(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nDuty);

            displayStation->ledsOled->ledsVar.changes = ACTUALIZE_ROW_DATA;
            allowPass2 = true;
            Serial.println("[webHandle.cpp]: save and show data");   
          }
        }
        // >>> Starts Tests if button "Start test" was pressed
        else if (path.startsWith("/tests/")){
          Serial.println("[station.cpp]: starting tests...");

            displayStation->ledsOled->ledsVar.startTests = true;
            Serial.println(displayStation->ledsOled->ledsVar.startTests);
        }
        // >>> If "Stop Tests" was pressed
        else if (path.startsWith("/stop/")){
          Serial.println("[station.cpp]: stopping tests...");
          displayStation->ledsOled->ledsVar.stopTests = true;
        }
        // >>> Get actual active card
        else if (path.startsWith("/selected/")){
          int activeCard = 0;
          StaticJsonDocument<256> nCard;
          DeserializationError error = deserializeJson(nCard, body);

          if (error) {
            Serial.print(F("[station.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }
          
          activeCard = nCard["card"];
          Serial.printf("[station.cpp]: show data of card ");
          Serial.println(activeCard);
        }
        // >>> Get selected wavelenght
        else if (path.startsWith("/wavelenght/")){
          StaticJsonDocument<256> wl;
          DeserializationError error = deserializeJson(wl, body);

          if (error) {
            Serial.print(F("[station.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }
          
          if(displayStation->ledsOled->ledsVar.startTests == false){
            displayStation->ledsOled->ledsVar.ledsWavelength = wl["wavelenght"];
            Serial.printf("[station.cpp]: wavelenght: ");
            Serial.println(displayStation->ledsOled->ledsVar.ledsWavelength);
          }
        }
        // >>> Move leds to origin if "Origin" was pressed
        else if (path.startsWith("/origin/")){
          
          //stepper->nSteps = 1000;
          //displayStation->ledsOled->changes = MOVE_STEPPER;

          if(displayStation->ledsOled->ledsVar.startTests == false){
            displayStation->ledsOled->ledsVar.changes = CALIBRATE_STEPPER;
            Serial.println("[station.cpp]: moving leds to origin");
          }
        }
        // >>> Move one step
        else if (path.startsWith("/oneStep/")){
          StaticJsonDocument<256> wl;
          DeserializationError error = deserializeJson(wl, body);

          if (error) {
            Serial.print(F("[station.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }
          if(displayStation->ledsOled->ledsVar.startTests == false){
            stepper->stepperMotorVar.nSteps = 20;
            displayStation->ledsOled->ledsVar.changes = MOVE_STEPPER;
            stepper->stepperMotorVar.direction = true;
            Serial.println("[station.cpp]: oneStep ");
          }

        }
        // >>> Move to next row
        else if (path.startsWith("/nextRow/")){
          StaticJsonDocument<256> wl;
          DeserializationError error = deserializeJson(wl, body);

          if (error) {
            Serial.print(F("[webHandle.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }

          if(displayStation->ledsOled->ledsVar.startTests == false){
            stepper->stepperMotorVar.nSteps = 895;

            /* check direction */
            if (stepper->stepperMotorVar.direction ==  true){
              Serial.println(stepper->stepperMotorVar.rows);
              if (stepper->stepperMotorVar.rows >= 1 && stepper->stepperMotorVar.rows < 9){
                stepper->stepperMotorVar.rows ++;
                digitalWrite(DIR, HIGH);
              }
            }
            else if (stepper->stepperMotorVar.direction ==  false){
              if (stepper->stepperMotorVar.rows >= 2 && stepper->stepperMotorVar.rows <= 10){
                stepper->stepperMotorVar.rows --;
                digitalWrite(DIR, LOW);
              }
            }

            displayStation->ledsOled->ledsVar.changes = MOVE_STEPPER;
            Serial.println("[webHandle.cpp]: next Row ");
          }
        }
        // >>> Show on screen selected card
        else if (path.startsWith("/show/")){
          StaticJsonDocument<256> show;
          DeserializationError error = deserializeJson(show, body);

          if (error) {
            Serial.print(F("[station.cpp]: DeserializeJson() failed: "));
            Serial.println(error.c_str());
            return;
          }
          /* esto mejor cambiarlo, es muy lío */
          //this->pwm->rowNumber = show["row"];
          //this->pwm->column = show["column"];
        }
      }
      response->addHeader("Access-Control-Allow-Methods", "GET, POST");
      response->addHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
      response->addHeader("Access-Control-Allow-Origin","*");
      request->send(response);   
    });

    asyncServer->onNotFound(vAsyncHandleNotFound);
    asyncServer->begin();
    Serial.printf("[webHandle.cpp]: Server as a Run Station\n");
}

int stationMode::iGetRowNumber(String path){
  String row_num;
  int ind1, ind2;

  ind1 = path.indexOf("/");
  ind1 = path.indexOf("/", ind1+1);
  ind2 = path.indexOf("/", ind1+1);
  row_num = path.substring(ind1+1, ind2);

  return row_num.toInt();
}
String stationMode::iGetRowLetter(String path){
  String row_letter;
  int ind1, ind2;

  ind1 = path.indexOf("/");
  ind1 = path.indexOf("/", ind1+1);
  ind1 = path.indexOf("/", ind1+1);
  ind2 = path.indexOf("/", ind1+1);
  row_letter = path.substring(ind1+1, ind2);

  return row_letter;
}

void stationMode::vActualiceDataWeb(){
  if (displayStation->ledsOled->ledsVar.startTests == false  && allowPass1 == true) {
    power = "0"; frequency = "0"; duty  = ""; timeTest = "0";
    active = ""; column = "";
    active = active + "Inactive"; column = column + "Column --";
    allowPass1 = false;
  }
  else if (displayStation->ledsOled->ledsVar.startTests == true){
    active = ""; column = ""; power = ""; frequency = ""; duty  = ""; timeTest = "";
    active = active + "Active";
    column = column + "Column " + String(displayStation->ledsOled->ledsVar.actualColumn) +  String(stationVar.columnLetter);
    power = power + String(float(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nPower));
    frequency = frequency + String(int(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nFrequency));
    duty = duty + String(int(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nDuty));

    timeTest = timeTest + String(int(60*displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nTime));
    allowPass2 = false;
  }
  else if (displayStation->ledsOled->ledsVar.startTests == true && allowPass2 == true){
    timeTest = "";
    timeTest = timeTest + String(int(60*displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nTime));
    allowPass2 = false;
  }
  else if (allowPass2 == true){
    active = ""; column = ""; power = ""; frequency = ""; duty  = ""; timeTest = "";
    active = active + "Inactive";
    column = column + "Column " + String(displayStation->ledsOled->ledsVar.actualColumn) +  String(stationVar.columnLetter);
    power = power + String(float(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nPower));
    frequency = frequency + String(int(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nFrequency));
    duty = duty + String(int(displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nDuty));

    timeTest = timeTest + String(int(60*displayStation->ledsOled->ledsVar.dataRow[displayStation->ledsOled->ledsVar.actualColumn][displayStation->ledsOled->ledsVar.actualRow].nTime));
    allowPass2 = false;
  }
}
void stationMode::vAsyncHandleNotFound(AsyncWebServerRequest *request){
  //Handle Unknown Request
  request->send(404);
}