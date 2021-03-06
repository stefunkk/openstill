#ifndef __DATACONTEXT_H__
#define __DATACONTEXT_H__
#include <Arduino.h>
#include <DallasTemperature.h>
#include "StillNotification.h"

class StillDataContextClass
{
public:
    StillDataContextClass(DeviceAddress &_shelf10Address, DeviceAddress &_headAddress, DeviceAddress &_tankAddress, DeviceAddress &_waterAddress,
                          String _shelf10Name, String _headName, String _tankName, String _waterName);
    DeviceAddress& shelf10Address;
    DeviceAddress& headAddress;
    DeviceAddress& tankAddress;
    DeviceAddress& waterAddress;
    String shelf10Name;
    String headName;
    String tankName;
    String waterName;
    
    double tempOfTheDayDeviation = 0;
    int tempOfTheDayNotificationDelayInSeconds = 0;
    double tempOfTheDay = 0;
    unsigned long tempofTheDayNotificationTime = 0;

    StillNotificationStruct notifications[10]; 
    bool findSensors = false;
    bool clearCsv = false;
    DeviceAddress foundDevices[4] = {};
    String foundDeviceString[4] = {};

    bool shelf10TemperatureNotificationSent = false;
    bool headerTemperatureNotificationSent = false;
    bool tankTemperatureNotificationSent = false;
    bool waterTemperatureNotificationSent = false;

    String ipAddress = "";
    bool isIpShown = false;
};


#endif // __DATACONTEXT_H__