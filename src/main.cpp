#include <Arduino.h>
#include <BluetoothSerial.h>
#include <string.h>
#include <WebServer.h>
#include <WiFi.h>

#include "tasks.h"

Adafruit_SSD1306 display_(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
hw_timer_t * timer = NULL;

leds ledsParam;
stepperMotor stepper;
oled display(&ledsParam, &stepper);
softAPMode softAP;
stationMode station(&display, &stepper);
wifiModule wifiMode(&softAP, &station);

// Set Set static IP address
IPAddress local_IP(192,168,1, 131); 
IPAddress gateway(192,168,1, 131);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);     //optional
IPAddress secondaryDNS(8, 8, 4, 4);   //optional

/* Data Web */
String active = "Inactive";
String column = "--";
String power = "0";
String frequency = "0";
String duty = "0";
String timeTest = "0";
String dataTime[MAX_N_ROWS][1];

/* Interrupt  */
int interrupt = false;

int blink = false;
int blinkLed = false;

int counter = false;
int allowPass1 = true;
int allowPass2 = true;



void setup() {
  Serial.begin(115200);
  Serial.println("\n");

  // PIN CONFIGURATION
  /* stepper motor */
  pinMode(STEP, OUTPUT); 
  pinMode(DIR, OUTPUT); 
  pinMode(EN, OUTPUT);
  pinMode(FC, OUTPUT);

  /* driver outputs */
  pinMode(POWER_PIN_1, OUTPUT);
  pinMode(DUTY_PIN_1, OUTPUT);
  pinMode(POWER_PIN_2, OUTPUT);
  pinMode(DUTY_PIN_2, OUTPUT);

  /* states Leds */
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  /* reset button */
  pinMode(RESET_PIN, OUTPUT);

  /* PWM INIT */
  digitalWrite(POWER_PIN_1, LOW);
  digitalWrite(POWER_PIN_2, LOW);

  digitalWrite(DUTY_PIN_1, LOW);
  digitalWrite(DUTY_PIN_2, LOW);

  /* configures static ip adress */
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  Wire.begin(SDA, SCL);

  /* eeprom */
  eeprom_init();
  if (!eeprom_init()){
    DEBUG_MSG("Failed initializing EEPROM\n");
  }

  //eeprom_write(EEPROM_SSID_STA_KEY, "");
  //eeprom_write(EEPROM_PASWD_STA_KEY, "");
  //eeprom_write(EEPROM_STEPPER, "");

  /* tasks */
  // Handle web pages (credentialWifi page and photodynamicTests page)
  TaskHandle_t xHandleWeb = NULL;
  Serial.println("[main.cpp]: Web task created");
  xTaskCreate(vTaskWeb, "Main Task", TASK_STACK_SIZE, (void*)&wifiMode, TASK_PRIORITY + 1, &xHandleWeb);
  configASSERT(xHandleWeb);

  // Handle leds drivers
  TaskHandle_t xHandleDrivers = NULL;
  Serial.println("[main.cpp]: Handle drivers Task creation");
  xTaskCreate(vTaskDrivers, "Set up Drivers Tasks", TASK_STACK_SIZE, (void*)&wifiMode, TASK_PRIORITY + 1, &xHandleDrivers);
  configASSERT(xHandleDrivers);

  // Handle outputs
  TaskHandle_t xHandleOledStepper = NULL;
  Serial.println("[main.cpp]: Oled and Stepper Task creation");
  xTaskCreate(vTaskOutputs, "Set Up OLED Task", TASK_STACK_SIZE, (void*)&station, TASK_PRIORITY + 1 , &xHandleOledStepper);
  configASSERT(xHandleOledStepper);
 
}

void loop() {
 vTaskDelay(200);
}