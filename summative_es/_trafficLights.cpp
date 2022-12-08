#ifdef WE_WANT_TO_DELETE_THIS


#include "trafficLights.h"
#include <Arduino.h>
#include "Concurrent.h"

trafficLights::trafficLights()
{
  module_delay = 2000;
  
}

void trafficLights::runLights()
{
  if (moduleStep)
    {
      switch(lightsState)
      {
        case 0:
          HAL_amberLed1On;
          HAL_amberLed2On;
          moduleDelay = 2000;
          lightsState = 1;
          break;
        case 1:
          HAL_amberLed1Off;
          HAL_amberLed2Off;
          HAL_redLed1On;
          HAL_redLed2On;
          moduleDelay = 1000;
          lightsState = 2;
          break;
        case 2:
          HAL_amberLed1On;
          HAL_redLed1On;
          HAL_redLed2On;
          moduleDelay = 1000;
          lightsState = 3;
          break;
        case 3:
          HAL_amberLed1Off;
          HAL_redLed1Off;
          HAL_greenLed1On;
          HAL_redLed2On;
          switch (priority) {
            case 0:
              moduleDelay = 6000;
              break;
            case 1:
              moduleDelay = 8000;
              break;
            case 2:
              moduleDelay = 4000;
              break;
          }
          lightsState = 4;
          break;
        case 4:
          HAL_greenLed1Off;
          HAL_amberLed1On;
          HAL_redLed2On;
          moduleDelay = 2000;
          lightsState = 5;
          break;
        case 5:
          HAL_amberLed1Off;
          HAL_redLed1On;
          HAL_redLed2On;
          moduleDelay = 1000;
          lightsState = 6;
          break;
        case 6:
          HAL_redLed1On;
          HAL_redLed2On;
          HAL_amberLed2On;
          moduleDelay = 1000;
          lightsState = 7;
          break;
        case 7:
          HAL_redLed1On;
          HAL_redLed2Off;
          HAL_amberLed2Off;
          HAL_greenLed2On;
          switch (priority) {
            case 0:
              moduleDelay = 6000;
              break;
            case 1:
              moduleDelay = 4000;
              break;
            case 2:
              moduleDelay = 8000;
              break;
          }
          lightsState = 8;
          break;
        case 8:
          HAL_redLed1On;
          HAL_greenLed2Off;
          HAL_amberLed2On;
          moduleDelay = 2000;
          lightsState = 1;
          break;
      }
    }
}

#endif
