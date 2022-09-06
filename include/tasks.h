#ifndef TASKS_H 
#define TASKS_H

#include "wifiModule.h"
#include "oled.h"

void vTaskWeb(void * param);
void vTaskDrivers(void *param);
void vTaskOutputs(void *param);

void vInterruptBlink();
void vInterruptCounter();

void vTimerOn();

#endif