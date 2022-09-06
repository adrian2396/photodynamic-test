#include "wifiModule.h"

wifiModule *this_;

extern hw_timer_t * timer;

extern int interrupt;
extern int blink;
extern int blinkLed;

// ------------------- WIFIMODULE CLASS METHODS ------------------//
wifiModule::wifiModule(softAPMode *softAP_, stationMode * station_){
    softAP = softAP_;
    station = station_;
    this_ = this;
}

wifiModule::~wifiModule(){
}

void wifiModule::vSelectWifiMode(){
    softAP->softAPVar.username_sta = eeprom_read(EEPROM_SSID_STA_KEY);
    softAP->softAPVar.password_sta = eeprom_read(EEPROM_PASWD_STA_KEY);

    Serial.println(softAP->softAPVar.username_sta);
    Serial.println(softAP->softAPVar.password_sta);

    if (softAP->softAPVar.username_sta.length() > 1 && softAP->softAPVar.password_sta.length() > 1){

        softAP->softAPVar.username_sta.toCharArray(softAP->softAPVar.username_sta_array, sizeof(softAP->softAPVar.username_sta_array));
        softAP->softAPVar.password_sta.toCharArray(softAP->softAPVar.password_sta_array, sizeof(softAP->softAPVar.password_sta_array));

        Serial.println("[webHandle.cpp]: Got connection parameters");
        
        WiFi.mode(WIFI_STA);
        WiFi.begin(softAP->softAPVar.username_sta_array, softAP->softAPVar.password_sta_array);

        int retries = 50;

        //station->displayStation->ledsOled->ledsVar.changes = ACTUALIZE_DISPLAY_MESSAGES;
        //station->displayStation->oledVar.oledMessages = CONECTING_WIFI;
        timerAlarmEnable(timer);
        interrupt = BLINK;
        blinkLed = RED;
        while (WiFi.status() != WL_CONNECTED && retries > 0) {
            Serial.println("[webHandle.cpp]: Connecting to WiFi..");
            retries --;
            vTaskDelay(500);
        }
        timerAlarmDisable(timer);
        if(WiFi.status() != WL_CONNECTED) {
            Serial.println("[webHandle.cpp]: Invalid credentials, restarting...");
            eeprom_write(EEPROM_SSID_STA_KEY, "");
            eeprom_write(EEPROM_PASWD_STA_KEY, "");
            eeprom_commit();
            
            //station->displayStation->ledsOled->ledsVar.changes = ACTUALIZE_DISPLAY_MESSAGES;
            //station->displayStation->oledVar.oledMessages = INVALID_CREDENTIALS; 

            ESP.restart();

            vTaskDelay(5);
        }
        else {
          DEBUG_MSG("\n[webHandle.cpp]: WiFi connected to IP address: %s\n", WiFi.localIP().toString().c_str());
          Serial.println("[webHandle.cpp]: Connected to the WiFi network");
          runMode = STATION_MODE;
          station->runAsStation();

          vTaskDelay(1000);

          station->stepper->vCalibrateStepper(10000, false);
          station->stepper->stepperMotorVar.direction = true;

          digitalWrite(GREEN, HIGH);
          digitalWrite(RED, LOW); 
        }
    } 
    else {  
        Serial.println("[webHandle.cpp]: Server As a AP");
        runMode = SOFT_AP_MODE;
        WiFi.softAPmacAddress(softAP->softAPVar.mac);
        softAP->runAsAPServer(softAP->softAPVar.mac);

        vTaskDelay(1000);

        station->stepper->vCalibrateStepper(10000, false);
        station->stepper->stepperMotorVar.direction = true;

        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
    }    
}

void wifiModule::vMessages(){
}