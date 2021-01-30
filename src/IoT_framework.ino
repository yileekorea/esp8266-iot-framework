#include <Arduino.h>
#include "LittleFS.h"

#include "WiFiManager.h"
#include "webServer.h"
#include "updater.h"
#include "fetch.h"
#include "configManager.h"
#include "timeSync.h"

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println("Hello world-1");

    LittleFS.begin();
    GUI.begin();
    configManager.begin();
    WiFiManager.begin(configManager.data.projectName);
    timeSync.begin();

    Serial.println("Hello world-2");
}

void loop()
{
    //software interrupts
    WiFiManager.loop();
    updater.loop();

    //your code here
}
