#include "oled.h"


extern Adafruit_SSD1306 display_;


oled::oled(leds *ledsOled_, stepperMotor *stepper_){
    ledsOled = ledsOled_;
    stepper = stepper_;
}

oled::~oled(){
}

void oled::vOldedValues(){
  display_.setTextSize(1);
  display_.setTextColor(WHITE);
  display_.setCursor(0, 10);

  // Inicialize variables
  oledVar.posY[nROWS] = 0;
  oledVar.posY[FREQUENCY] = 16;
  oledVar.posY[TIME] = 33;
  oledVar.posY[POT] = 16;
  oledVar.posY[DUTY] = 33;

  oledVar.posX[nROWS] = 0;
  oledVar.posX[FREQUENCY] = 0;
  oledVar.posX[TIME] = 0;
  oledVar.posX[POT] = 64;
  oledVar.posX[DUTY] = 64;

  oledVar.sOledNameSection[FREQUENCY] = "FREQ";
  oledVar.sOledNameSection[POT] = "POT.";
  oledVar.sOledNameSection[DUTY] = "DUTY";
  oledVar.sOledNameSection[TIME] = "TIME";

  for (int i = 1; i <= MAX_N_ROWS; i++){
    oledVar.sRows[i] = "COLUMN ";
    oledVar.sRows[i] += (String) i;
    //Serial.println(sRows[i]); 
  }
  Serial.println("[oled.cpp]: OLED init");
}
void oled::vShowData(int actualRow, int column){
  //String Column = "";
  //display_.setCursor(1,1);

  /* show actual row */
  display_.clearDisplay();
  display_.clearDisplay();
  display_.display();
  

  display_.fillRect(0, 0,  128 , 15, SSD1306_WHITE);
  display_.display();


  display_.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display_.setTextSize(1);

  if (actualRow < ROW10)  display_.setCursor(47 -3, 5);
  else display_.setCursor(47-10, 5);

  display_.println(oledVar.sRows[actualRow]);
  display_.display();

  /* show actual column */
  display_.fillRect(0, 50, 128 , 15, SSD1306_WHITE);
  display_.display();

  display_.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display_.setTextSize(1);

  if (column  == 0) { oledVar.Column = "A"; display_.setCursor(62 - 12, 53);}
  else if (column == 1) {oledVar.Column = "B"; display_.setCursor(62 - 12, 53);}

  display_.print("ROW ");
  display_.println(oledVar.Column);
  display_.display();

  /* draw Sections */
  for (int i = FREQUENCY; i <= DUTY; i++){
    display_.fillRect(oledVar.posX[i], oledVar.posY[i], 27, 15, SSD1306_BLACK);
    display_.setTextColor(SSD1306_WHITE ,SSD1306_BLACK);
    display_.setCursor(1 + oledVar.posX[i], oledVar.posY[i] + 4);
    display_.setTextSize(1);
    display_.println(oledVar.sOledNameSection[i]);
    display_.display();

    // show values 
    display_.fillRect(30 + oledVar.posX[i], oledVar.posY[i], 33, 15, SSD1306_WHITE);
    display_.display();
    display_.setCursor(oledVar.posX[i] + 30, oledVar.posY[i] + 4);
    display_.setTextSize(1);
    display_.setTextColor(SSD1306_BLACK, SSD1306_WHITE);

    if (i == FREQUENCY) {
      if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 0 && ledsOled->ledsVar.dataRow[actualRow][column].nFrequency < 10){
        display_.setCursor(oledVar.posX[i] + 30 + 13, oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 10 && ledsOled->ledsVar.dataRow[actualRow][column].nFrequency < 100){
        display_.setCursor(oledVar.posX[i] + 30 + 10, oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 100 && ledsOled->ledsVar.dataRow[actualRow][column].nFrequency < 1000){
        display_.setCursor(oledVar.posX[i] + 30 + 7, oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 1000 && ledsOled->ledsVar.dataRow[actualRow][column].nFrequency < 10000){
        display_.setCursor(oledVar.posX[i] + 30 + 2, oledVar.posY[i] + 4);
        display_.print(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency/1000);
        display_.println("K");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 10000 && ledsOled->ledsVar.dataRow[actualRow][column].nFrequency < 100000){
        display_.setCursor(oledVar.posX[i] + 30 + 8,oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency/1000));
        display_.println("K");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nFrequency >= 100000){
        display_.setCursor(oledVar.posX[i] + 30 + 5, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nFrequency/1000));
        display_.println("K");
      } 
      display_.display();  
    }
    else if (i == TIME){
      if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 0 && ledsOled->ledsVar.dataRow[actualRow][column].nTime < 10){
        display_.setCursor(oledVar.posX[i] + 30 + 13, oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nTime));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 10 && ledsOled->ledsVar.dataRow[actualRow][column].nTime < 100){
        display_.setCursor(oledVar.posX[i] + 30 + 10,oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nTime));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 100 && ledsOled->ledsVar.dataRow[actualRow][column].nTime < 1000){
        display_.setCursor(oledVar.posX[i] + 30 + 7, oledVar.posY[i] + 4);
        display_.println(int(ledsOled->ledsVar.dataRow[actualRow][column].nTime));
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 1000 && ledsOled->ledsVar.dataRow[actualRow][column].nTime < 10000){
        display_.setCursor(oledVar.posX[i] + 30 + 2, oledVar.posY[i] + 4);
        display_.print(ledsOled->ledsVar.dataRow[actualRow][column].nTime/1000);
        display_.println("K");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 10000 && ledsOled->ledsVar.dataRow[actualRow][column].nTime < 100000){
        display_.setCursor(oledVar.posX[i] + 30 + 8, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nTime/1000));
        display_.println("K");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nTime >= 100000){
        display_.setCursor(oledVar.posX[i] + 30 + 5, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nTime/1000));
        display_.println("K");
      } 
      display_.display();
    }  
    else if (i == POT){
      display_.setCursor(oledVar.posX[i] + 30 + 4, oledVar.posY[i] + 4);
      display_.println(ledsOled->ledsVar.dataRow[actualRow][column].nPower);
      display_.display();
    }
    else if (i == DUTY){
      if (ledsOled->ledsVar.dataRow[actualRow][column].nDuty >= 0 && ledsOled->ledsVar.dataRow[actualRow][column].nDuty < 10){
        display_.setCursor(oledVar.posX[i]  + 42, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nDuty));
        display_.println("%");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nDuty >= 10 && ledsOled->ledsVar.dataRow[actualRow][column].nDuty < 100){
        display_.setCursor(oledVar.posX[i] + 35, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nDuty));
        display_.println("%");
      }
      else if (ledsOled->ledsVar.dataRow[actualRow][column].nDuty == 100){
        display_.setCursor(oledVar.posX[i] + 32, oledVar.posY[i] + 4);
        display_.print(int(ledsOled->ledsVar.dataRow[actualRow][column].nDuty));
        display_.println("%");
      }
      display_.display();
      vTaskDelay(1); 
    }
  }
}

void oled::displayMessages(int message){
  display_.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  display_.setCursor(0,0);
  display_.setTextSize(1);
  display_.clearDisplay();
  switch (message)
  {
    case AP_SERVER:
      displayAP("192.168.4.1", "PhotodynamicTest", "12345678");
    break;
    case ENTER_CREDENTIALS:
      display_.println("Enter your wifi credentials");
      display_.display();
      break;
    case CONECTING_WIFI:
      /*display_.setCursor(30,26);
      if (oledVar.number == 0){
        display_.println("Connecting.");
        display_.display();
      }
      if (oledVar.number == 1){
        display_.println("Connecting..");
        display_.display();
      }
      if (oledVar.number == 2){
        display_.println("Connecting...");
        display_.display();
      }*/
      break;
    case INVALID_CREDENTIALS:
      display_.setCursor(2,26);
      display_.println("INVALID CREDENTIALS");
      display_.display();
      break;
    case TEST_COMPLETE:
      display_.setCursor(2,26);
      display_.println("TEST COMPLETED");
      display_.display();
      break;
    case WIFI_CONNECTED:
      display_.clearDisplay();
      display_.display();

      display_.setCursor(30,7);
      display_.println("  CONNECTED!");
      display_.display();

      display_.setCursor(0,30);
      display_.printf("GO TO:  172.20.10.9");

      display_.display();

      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      break;
    case CALIBRATE_STEPPER:
      if(oledVar.number == 0){
        display_.setCursor(7,26);
        display_.println("MOVING TO ORIGIN...");
        display_.display();
      }
      else if (oledVar.number == 1) {
        display_.clearDisplay();
        display_.display();
      }
      break;
    case WELCOME:
      display_.setTextSize(1);
      display_.setCursor(12,20);
      display_.setTextColor(WHITE);
      display_.println("PHOTODYNAMIC TEST");
      display_.setCursor(38,40);
      display_.println("WELCOME!!");
      display_.display();
      vTaskDelay(2000);
      /*display_.clearDisplay();
      display_.setTextSize(2);
      display_.setCursor(15,20);
      display_.println("   .");
      display_.display();
      vTaskDelay(700);
      display_.setCursor(15,20);
      display_.println("    .");
      display_.display();
      vTaskDelay(700);
      display_.setCursor(15,20);
      display_.println("     .");
      display_.display();
      vTaskDelay(1000);*/
      display_.clearDisplay();
      display_.display();
      break;
    default:
      break;
    oledVar.oledMessages = -1;
    display_.setTextSize(1);
  }

}
void oled::displayAP(String ip_address, String name, String password) {
  //display_.clearDisplay();
  display_.setCursor(18,7);
  display_.setTextSize(1);
  display_.printf("URL: ");
  display_.display();
  display_.println(ip_address);
  display_.display();

  display_.setCursor(0,25);
  display_.printf("Name:");
  display_.display();
  display_.println(name);
  display_.display();

  display_.setCursor(12,45);
  display_.printf("Password: ");
  display_.display();
  display_.println(password);
  display_.display(); 
}


void oled::vActualizeChanges(){
  switch (ledsOled->ledsVar.changes){
    case MOVE_STEPPER:
        Serial.println("[oled.cpp]: Moving Steeper...");
        Serial.println(stepper->stepperMotorVar.nSteps);
        stepper->vMoveStepper(stepper->stepperMotorVar.nSteps, stepper->stepperMotorVar.direction);
        ledsOled->ledsVar.changes = DO_NOTHING;
        vTaskDelay(1);
        break;
    case ACTUALIZE_ROW_DATA:
        Serial.println("[oled.cpp]: actualizing dislay...");
        vShowData(ledsOled->ledsVar.actualRow, ledsOled->ledsVar.actualColumn);
        ledsOled->ledsVar.changes = DO_NOTHING;
        vTaskDelay(1);
        break;
    case ACTUALIZE_DISPLAY_MESSAGES:
        Serial.println("[oled.cpp]: actualizing display messages...");
        displayMessages(oledVar.oledMessages);
        ledsOled->ledsVar.changes = DO_NOTHING;
        vTaskDelay(1);
        break;
    case CALIBRATE_STEPPER:
        Serial.println("[oled.cpp]: Moving stepper to origin...");
        stepper->vCalibrateStepper(10000, false);
        ledsOled->ledsVar.changes = DO_NOTHING;
        vTaskDelay(1);
        break;
    case DO_NOTHING:
        vTaskDelay(1);
        break;
    default:
    Serial.println("xD");
        break;
  }
  //ledsOled->vActualizeGRLeds();
}