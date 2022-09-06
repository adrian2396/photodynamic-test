#include "tasks.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* External variables */
extern hw_timer_t * timer;
extern Adafruit_SSD1306 display_; 

extern String active;
extern String column;
extern String power;
extern String frequency;
extern String duty;
extern String timeTest;

extern int interrupt;
extern int blink;
extern int blinkLed;
extern int counter;
extern int allowPass1;
extern int allowPass2;

/*void IRAM_ATTR onTimer() {
    allowPass2 = true;
    timeTest = "";
    counter = counter - 1;
    Serial.println(counter);
    timeTest = timeTest + String(counter);

    if (counter == 0) timerAlarmDisable(timer);
}*/

/* INTERRUPTS FUNCTIONS */
void vInterruptBlink(){
    if (blink == true) {
        digitalWrite(blinkLed, LOW);
        blink = false;
    }
    else if (blink ==  false){
        digitalWrite(blinkLed, HIGH);
        blink = true;
    }
}
void vInterruptCounter(){
    
}
void IRAM_ATTR onTimer() {
    switch (interrupt)
    {
    case BLINK:
        vInterruptBlink();
        break;
    case COUNTER:
        vInterruptCounter();
        break;
    default:
        break;
    }
}

/* TASKS FUNCTIONS */
void vTaskWeb(void * param){

    pthread_mutex_init(&mutex, 0);

    wifiModule xWeb = *(wifiModule*)param;

    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(EN, HIGH);

    vTaskDelay(2000);

    /* INICIALIZE WEB */
    Serial.println("[tasks.cpp]: Inicialize Web");
    xWeb.vSelectWifiMode();
    //xWeb.vMessages();           // actualice display an GR leds

    while(1) { 
        /* run as station: ssid */
        pthread_mutex_lock(&mutex);
        if (xWeb.runMode == SOFT_AP_MODE){   
            xWeb.softAP->server->handleClient();
            vTaskDelay(1); 
        }
        /* run as station: esp connect to internet */
        else if (xWeb.runMode == STATION_MODE) {
            xWeb.station->vActualiceDataWeb();
            vTaskDelay(10);
        }
        pthread_mutex_unlock(&mutex);
        vTaskDelay(1);
    }
}

void vTaskDrivers(void *param){
    wifiModule xLeds = *(wifiModule*)param;

    Serial.println("[tasks.cpp]: Inicialize drivers");

    /* INTERRUPS */
    pthread_mutex_lock(&mutex);
    timer = timerBegin(2, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 500000, true);
    timerAlarmDisable(timer);
    pthread_mutex_unlock(&mutex);

    while (1){
        /* starts photodynamic tests */
        if (xLeds.station->displayStation->ledsOled->ledsVar.startTests == true){
            pthread_mutex_lock(&mutex);
            vTaskDelay(2000);
            timerAlarmEnable(timer);
            pthread_mutex_unlock(&mutex);
            xLeds.station->displayStation->ledsOled->vStartTests();
        }
        else {
            pthread_mutex_lock(&mutex);
            timerAlarmDisable(timer); 
            pthread_mutex_unlock(&mutex);
        }
        pthread_mutex_lock(&mutex);
        xLeds.station->displayStation->ledsOled->vActualizeGRLeds();
        pthread_mutex_unlock(&mutex);
        vTaskDelay(1);
    }
}

void vTaskOutputs(void *param){
    stationMode xOutputs = *(stationMode*)param;

    Serial.println("[tasks.cpp]: Inicialize Outputs");

    /* OLED INIT */
    if(!display_.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println("[oled.cpp]: SSD1306 allocation failed");
        for(;;); // Don't proceed, loop forever
    }

    pthread_mutex_lock(&mutex);
    Serial.println("[tasks.cpp]: oled init");
    display_.display();
    xOutputs.displayStation->vOldedValues();
    xOutputs.displayStation->displayMessages(WELCOME);
    pthread_mutex_unlock(&mutex);

    /* ORIGIN */
    vTaskDelay(1000);

    pthread_mutex_lock(&mutex);
    Serial.println("[tasks.cpp]: Moving stepper to origin");
    pthread_mutex_unlock(&mutex);

    while (1){
        xOutputs.displayStation->vActualizeChanges();
        if (xOutputs.displayStation->ledsOled->ledsVar.actualizeOled == true){
            xOutputs.displayStation->vShowData(xOutputs.displayStation->ledsOled->ledsVar.actualRow, xOutputs.displayStation->ledsOled->ledsVar.actualColumn);
            xOutputs.displayStation->ledsOled->ledsVar.actualizeOled = false;
        }
        vTaskDelay(1);
    } 
}

