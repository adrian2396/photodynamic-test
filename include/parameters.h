#ifndef PARAMETERS_H 
#define PARAMETERS_H

#define BLINK           1
#define BLINK_RED       1
#define BLINK_GREEN     2
#define COUNTER         2

/* enum web */
enum runningAs{RUNNING_NULL = -1, SOFT_AP_MODE, STATION_MODE};
enum columns{COL_NULL = -1, COL_A, COL_B};
enum clickOn {NONE = -1, SAVE, START_TEST, STOP_TEST, WAVE, N_ROW, O_STEP, ORIGIN, CHECK_BOX};

/* enum leds */
enum pwmChannels{channel_1 = 1, channel_2, channel_3, channel_4};
enum wavelengthLeds{NM_660 = 1, NM_810, NM_1300};

/* enum display */
enum verticalStates{DRAW_ALL = - 1, nROWS, FREQUENCY, TIME, POT, DUTY};
enum nRows{ROW1 = 1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8, ROW9, ROW10};
enum webOledDisplay{AP_SERVER = 0, STATION, ENTER_CREDENTIALS, CONECTING_WIFI, WIFI_CONNECTED, INVALID_CREDENTIALS, SHOW_CARD, WELCOME, TEST_COMPLETE, CALIBRATE_STEPPER};

/* enum red and green leds */
enum statLedsRG{L_S_NULL = -1, GREEN_ON_RED_OFF, GREEN_OFF_RED_ON, GREEN_OFF_RED_OFF, GREEN_BLINK_RED_OFF, GREEN_BLINK_RED_ON,  RED_BLINK_GREEN_OFF,  RED_BLINK_GREEN_ON};
/* enum stepper */
enum oledStepper{CALIBRATE_, ONE_STEP, NEXT_ROW};

/* outputs Task */
enum outputs {DO_NOTHING = -1, MOVE_STEPPER = 0, STEPPER_ORIGIN, ACTUALIZE_DISPLAY_MESSAGES, ACTUALIZE_ROW_DATA , ACTUALIZE_RG_LEDS};

// TASK PARAMETERS
#define TASK_STACK_SIZE             5000
#define TASK_PRIORITY               0

// GENERAL PARAMETERS
#define ARRAY_SIZE                  35

// OLED SCREEN
#define SCREEN_WIDTH                128 
#define SCREEN_HEIGHT               64 
#define OLED_RESET                  -1 
#define SCL_PIN                     22
#define SDA_PIN                     21
#define BUTTON_PIN                  2

// PWM and OLED
#define DEFAULT_RESOLUTION               8
#define DEFAULT_RESOLUTION_STEPS         255  
#define DEFAULT_FREQ_POWER               10000
#define MAX_N_ROWS                       10
#define MAX_POWER                        3
#define MAX_DUTY                         100


#define POWER_PIN_1                      25
#define DUTY_PIN_1                       2
#define POWER_PIN_2                      26
#define DUTY_PIN_2                       15

#define RESET_PIN                        19

#define GREEN                            18
#define RED                              5


#endif