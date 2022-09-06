#include "leds.h"

leds::leds(){
}

leds::~leds(){
}

/* Extern variables */
extern String active;
extern String column;
extern String power;
extern String frequency;
extern String duty;
extern String dataTime[MAX_N_ROWS][1];

extern int counter;

extern int allowPass1;
extern int allowPass2;

void leds::vPwmColumnA(float power, float duty, int frequency){
  /* power */
  ledcSetup(channel_1, DEFAULT_FREQ_POWER, DEFAULT_RESOLUTION);
  ledcAttachPin(POWER_PIN_1, channel_1);
  delayMicroseconds(250);
  ledcWrite(channel_1, power);
  delay(1);
  /* duty */
  ledcSetup(channel_2, frequency, DEFAULT_RESOLUTION);
  ledcAttachPin(DUTY_PIN_1, channel_2);
  delayMicroseconds(250);
  ledcWrite(channel_2, duty);
  delay(1);
}
void leds::vPwmColumnB(float power, float duty, int frequency){
  /* power */
  ledcSetup(channel_3, DEFAULT_FREQ_POWER, DEFAULT_RESOLUTION);
  ledcAttachPin(POWER_PIN_2, channel_3);
  delayMicroseconds(250);
  ledcWrite(channel_3, power);
  delay(1);
  /* duty */
  ledcSetup(channel_4, frequency, DEFAULT_RESOLUTION);
  ledcAttachPin(DUTY_PIN_2, channel_4);
  delayMicroseconds(250);
  ledcWrite(channel_4, duty);
  delay(1);
}

void leds::vPwmColumnAoff(){
  digitalWrite(POWER_PIN_1, LOW);
  digitalWrite(DUTY_PIN_1, LOW);

}
void leds::vPwmColumnBoff(){
  digitalWrite(POWER_PIN_2, LOW);
  digitalWrite(DUTY_PIN_2, LOW);
}

void leds::vSaveTimes(){
  for (int i = 2; i<=MAX_N_ROWS; i++){
    dataTime[i][0] = String(int(ledsVar.dataRow[i][0].nTime));
    dataTime[i][0] = String(int(ledsVar.dataRow[i][1].nTime));
  }
}

void leds::vStartTests(){
  int transistorDutyA = 0;
  int transistorDutyB = 0;

  int dutyA = 0;
  int dutyB = 0;

  int timeA = 0;
  int timeB = 0;

  if (ledsVar.startTests == true){
    //vSaveTimes();

    /* Select leds (660nm, 810nm, 1300nm) */
    vDutys(); 

    for (int i = 2; i <= MAX_N_ROWS; i++){
      vPrintlnData(i);

      /* get duty transistors */
      transistorDutyA = (ledsVar.dataRow[i][0].nDuty*(255))/100; 
      transistorDutyB = (ledsVar.dataRow[i][1].nDuty*(255))/100; 

      /* get duty driver */
      dutyA = 20*ledsVar.dataRow[i][0].nPower -1;
      dutyB = 20*ledsVar.dataRow[i][1].nPower -1;

      /* get time */
      timeA = ledsVar.dataRow[i][0].nTime*60;
      timeB = ledsVar.dataRow[i][1].nTime*60;

      /* starts testing row A */
      if (ledsVar.dataRow[i][0].nPower != 0 && ledsVar.dataRow[i][0].nFrequency != 0 && ledsVar.dataRow[i][0].nDuty != 0){
        Serial.println("Starts Column A");
        vPwmColumnA(ledsVar.dutyDriverA[dutyA], transistorDutyA, ledsVar.dataRow[i][0].nFrequency);
        
        /* Timer On */
        counter = timeA;
        while (counter != 0)
        {
          vTaskDelay(1000);
        }   
      }

      /* starts testing row B */
      if (ledsVar.dataRow[i][1].nPower != 0 && ledsVar.dataRow[i][1].nFrequency != 0 && ledsVar.dataRow[i][1].nDuty != 0){
        Serial.println("Starts Column B");
        vPwmColumnB(ledsVar.dutyDriverB[dutyB], transistorDutyB, ledsVar.dataRow[i][1].nFrequency);
        
        /* Timer On */
        counter = timeA;
        while (counter != 0)
        {
          vTaskDelay(1000);
        } 
      }
    }
    ledsVar.startTests = false;
  }
}


void leds::vActualizeGRLeds(){
  switch (ledsVar.stateLedsGR){
  case GREEN_ON_RED_OFF:
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      ledsVar.stateLedsGR = L_S_NULL;
      vTaskDelay(1);
      break;
  case GREEN_OFF_RED_ON:
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);
      ledsVar.stateLedsGR = L_S_NULL;
      vTaskDelay(1);
      break;
  case GREEN_OFF_RED_OFF:
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      ledsVar.stateLedsGR = L_S_NULL;
      vTaskDelay(1);
  default:
      break;
  }
  ledsVar.stateLedsGR = -1;
}

void leds::vRGBlink(){
  switch (ledsVar.stateLedsGRBlink){
    case GREEN_BLINK_RED_ON:
      Serial.printf("1111");
      digitalWrite(RED, HIGH);
      if (ledsVar.blink == true) {
        digitalWrite(GREEN, HIGH);
        ledsVar.blink = false;
      }
      else {
        digitalWrite(GREEN, LOW);
        ledsVar.blink = true;
      }
      break;
    case RED_BLINK_GREEN_OFF:
      digitalWrite(GREEN, LOW);
      if (ledsVar.blink == true) {
        digitalWrite(RED, HIGH);
        ledsVar.blink = false;
      }
      else {
        digitalWrite(RED, LOW);
        ledsVar.blink = true;
      }
      break;
    case RED_BLINK_GREEN_ON:
        digitalWrite(GREEN, HIGH);
        if (ledsVar.blink == true) {
          digitalWrite(RED, HIGH);
          ledsVar.blink = false;
        }
        else {
          digitalWrite(RED, LOW);
          ledsVar.blink = true;
        }
    break;
    default:
    break;
  }
}


void leds::vPrintlnData(int actualRow){
    Serial.println("-----------------------------");
    Serial.println(ledsVar.dataRow[actualRow][COL_A].nFrequency);
    Serial.println(ledsVar.dataRow[actualRow][COL_A].nPower);
    Serial.println(ledsVar.dataRow[actualRow][COL_A].nDuty);
    Serial.println(ledsVar.dataRow[actualRow][COL_A].nTime);
    Serial.println(ledsVar.dataRow[actualRow][COL_B].nFrequency);
    Serial.println(ledsVar.dataRow[actualRow][COL_B].nPower);
    Serial.println(ledsVar.dataRow[actualRow][COL_B].nDuty);
    Serial.println(ledsVar.dataRow[actualRow][COL_B].nTime);
    Serial.println("-----------------------------");
    vTaskDelay(10);
}

void leds::vInicializeData(){
  for (int i = 1; i <= MAX_N_ROWS; i++){
    ledsVar.dataRow[i][COL_A].nTime = 0;
    ledsVar.dataRow[i][COL_A].nDuty = 0;
    ledsVar.dataRow[i][COL_A].nFrequency = 0;
    ledsVar.dataRow[i][COL_A].nPower = 0;

    ledsVar.dataRow[i][COL_B].nTime = 0;
    ledsVar.dataRow[i][COL_B].nDuty = 0;
    ledsVar.dataRow[i][COL_B].nFrequency = 0;
    ledsVar.dataRow[i][COL_B].nPower = 0;
  }
}

void leds::vDutys(){
  Serial.printf("[leds.cpp]: wavelenght: ");
  Serial.println(ledsVar.ledsWavelength);
  switch (ledsVar.ledsWavelength)
  {
  case NM_660:
    /* DRIVER A */
    ledsVar.dutyDriverA[1] = 15;
    ledsVar.dutyDriverA[2] = 23;
    ledsVar.dutyDriverA[3] = 28;
    ledsVar.dutyDriverA[4] = 34;
    ledsVar.dutyDriverA[5] = 40;
    ledsVar.dutyDriverA[6] = 45;
    ledsVar.dutyDriverA[7] = 50;
    ledsVar.dutyDriverA[8] = 55;
    ledsVar.dutyDriverA[9] = 60;
    ledsVar.dutyDriverA[10] = 65;
    ledsVar.dutyDriverA[11] = 69;
    ledsVar.dutyDriverA[12] = 74;
    ledsVar.dutyDriverA[13] = 77;
    ledsVar.dutyDriverA[14] = 81;
    ledsVar.dutyDriverA[15] = 84;
    /* DRIVER B */
    ledsVar.dutyDriverB[1] = 15;
    ledsVar.dutyDriverB[2] = 23;
    ledsVar.dutyDriverB[3] = 28;
    ledsVar.dutyDriverB[4] = 35;
    ledsVar.dutyDriverB[5] = 41;
    ledsVar.dutyDriverB[6] = 47;
    ledsVar.dutyDriverB[7] = 52;
    ledsVar.dutyDriverB[8] = 57;
    ledsVar.dutyDriverB[9] = 62;
    ledsVar.dutyDriverB[10] = 67;
    ledsVar.dutyDriverB[11] = 71;
    ledsVar.dutyDriverB[12] = 76;
    ledsVar.dutyDriverB[13] = 80;
    ledsVar.dutyDriverB[14] = 84;
    ledsVar.dutyDriverB[15] = 87;
    Serial.println("[leds.cpp]: 660 nm duty selected");
    break;
  case NM_810:
    /* DRIVER A */
    ledsVar.dutyDriverA[1] = 19;
    ledsVar.dutyDriverA[2] = 27;
    ledsVar.dutyDriverA[3] = 34;
    ledsVar.dutyDriverA[4] = 40;
    ledsVar.dutyDriverA[5] = 46;
    ledsVar.dutyDriverA[6] = 51;
    ledsVar.dutyDriverA[7] = 56;
    /* DRIVER B */
    ledsVar.dutyDriverA[1] = 19;
    ledsVar.dutyDriverA[2] = 27;
    ledsVar.dutyDriverA[3] = 34;
    ledsVar.dutyDriverA[4] = 40;
    ledsVar.dutyDriverA[5] = 46;
    ledsVar.dutyDriverA[6] = 51;
    ledsVar.dutyDriverA[7] = 56;
    Serial.println("[leds.cpp]: 810 nm duty selected");
    break;
  case NM_1300:
    Serial.println("[leds.cpp]: 1300 nm selected");
    break;
  default:
    break;
  }
}






































































































































































































/*
void leds::vDutyDriverA_660nm(){
  dutyDriverA_660nm[1] = 15;
  dutyDriverA_660nm[2] = 23;
  dutyDriverA_660nm[3] = 28;
  dutyDriverA_660nm[4] = 34;
  dutyDriverA_660nm[5] = 40;
  dutyDriverA_660nm[6] = 45;
  dutyDriverA_660nm[7] = 50;
  dutyDriverA_660nm[8] = 55;
  dutyDriverA_660nm[9] = 60;
  dutyDriverA_660nm[10] = 65;
  dutyDriverA_660nm[11] = 69;
  dutyDriverA_660nm[12] = 74;
  dutyDriverA_660nm[13] = 77;
  dutyDriverA_660nm[14] = 81;
  dutyDriverA_660nm[15] = 84;
}

void leds::vDutyDriverB_660nm(){
  dutyDriverB_660nm[1] = 15;
  dutyDriverB_660nm[2] = 23;
  dutyDriverB_660nm[3] = 28;
  dutyDriverB_660nm[4] = 35;
  dutyDriverB_660nm[5] = 41;
  dutyDriverB_660nm[6] = 47;
  dutyDriverB_660nm[7] = 52;
  dutyDriverB_660nm[8] = 57;
  dutyDriverB_660nm[9] = 62;
  dutyDriverB_660nm[10] = 67;
  dutyDriverB_660nm[11] = 71;
  dutyDriverB_660nm[12] = 76;
  dutyDriverB_660nm[13] = 80;
  dutyDriverB_660nm[14] = 84;
  dutyDriverB_660nm[15] = 87;
}

void leds::vDutyDriverA_810nm(){
  dutyDriverA_810nm[1] = 11;
  dutyDriverA_810nm[2] = 15;
  dutyDriverA_810nm[3] = 19;
  dutyDriverA_810nm[4] = 23;
  dutyDriverA_810nm[5] = 27;
  dutyDriverA_810nm[6] = 30;
  dutyDriverA_810nm[7] = 34;
  dutyDriverA_810nm[8] = 37;
  dutyDriverA_810nm[9] = 40;
  dutyDriverA_810nm[10] = 43;
  dutyDriverA_810nm[11] = 46;
  dutyDriverA_810nm[12] = 49;
  dutyDriverA_810nm[13] = 51;
  dutyDriverA_810nm[14] = 54;
  dutyDriverA_810nm[15] = 56;
}

void leds::vDutyDriverB_810nm(){
  dutyDriverB_810nm[1] = 11;
  dutyDriverB_810nm[2] = 15;
  dutyDriverB_810nm[3] = 19;
  dutyDriverB_810nm[4] = 24;
  dutyDriverB_810nm[5] = 28;
  dutyDriverB_810nm[6] = 31;
  dutyDriverB_810nm[7] = 35;
  dutyDriverB_810nm[8] = 39;
  dutyDriverB_810nm[9] = 42;
  dutyDriverB_810nm[10] = 46;
  dutyDriverB_810nm[11] = 49;
  dutyDriverB_810nm[12] = 52;
  dutyDriverB_810nm[13] = 54;
  dutyDriverB_810nm[14] = 57;
  dutyDriverB_810nm[15] = 59;
}
*/
