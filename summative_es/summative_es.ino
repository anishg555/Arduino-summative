#include "hal.h"

bool init_module0_clock;

void setup() {
  // put your setup code here, to run once:
  DDRD |= 0b11111100;
  init_module0_clock = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  {
    static unsigned long moduleTime, moduleDelay;
    static bool moduleStep;
    static unsigned char lightsState;
    static unsigned char priority; // 0 = equal, 1 = set 1, 2 = set 2

    if (init_module0_clock) {
      moduleTime = millis();
      moduleStep = false;
      init_module0_clock = false;
      lightsState = 0;
      priority = 0;
    }
    else {
      unsigned long m = millis();

      //if the module time exceeds the max delay, move on
      if ((m - moduleTime) > moduleDelay) {
        moduleTime = m;
        moduleStep = true;
      }
      else {
        moduleStep = false;
      }
    }

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
}
