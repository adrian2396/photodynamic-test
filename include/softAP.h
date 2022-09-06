#ifndef SOFTAP_H 
#define SOFTAP_H

#include <WiFi.h>
#include <WebServer.h>

#include "eprom.h"
#include "parameters.h"
#include "debug.h"

struct softAPVariables{
    String  username_sta = "";
    String  password_sta = "";

    char username_sta_array[33];                // SSID as a char array
    char password_sta_array[33];                // Password as a char array

    uint8_t mac[6];
};
typedef struct softAPVariables softAPVariables;

class softAPMode{
private:
    const char* SSID_PREFIX = "PhotodynamicTest-";         // SSID prefix as access point
    const char* PASSWORD    = "123456789";                 // Password as access point

    static void vFrontendWifiCredentials();
    void vGetWifiCredentials();
public:
    softAPMode();
    ~softAPMode();

    softAPVariables softAPVar;

    WebServer *server; 

    void runAsAPServer(uint8_t mac[]);
    static void vHandleNotFound();
};

#endif