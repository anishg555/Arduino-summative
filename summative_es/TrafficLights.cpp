#include "TrafficLights.h"
#include "hal.h"

//--------------------------------------------------------------
// Constructor
// Puts class into a sane state whenever an instance of the
// class is declared.
//--------------------------------------------------------------

TrafficLights::TrafficLights()
{
  isRunning = false;
  module_delay = 500;
  state = 0;
}


//--------------------------------------------------------------
// process()
//
// Member function that processes timed activity. It takes care
// of timeouts, running / not running etc.
// Returns: nothing
//--------------------------------------------------------------

void TrafficLights::process()
{
  // Only process the finite state machine on a 'tick' / 'step'
  if (actionTask())
  {
    switch (state)
    {
      case 0:
        HAL_amberLed1On;
        HAL_amberLed2On;
        module_delay = 2000;
        state = 1;
        break;
      case 1:
        HAL_amberLed1Off;
        HAL_amberLed2Off;
        HAL_redLed1On;
        HAL_redLed2On;
        module_delay = 1000;
        state = 2;
        break;
      case 2:
        HAL_amberLed1On;
        HAL_redLed1On;
        HAL_redLed2On;
        module_delay = 1000;
        state = 3;
        break;
      case 3:
        HAL_amberLed1Off;
        HAL_redLed1Off;
        HAL_greenLed1On;
        HAL_redLed2On;
        //switch (priority) {
        //  case 0:
            module_delay = 6000;
        //    break;
        //  case 1:
        //    module_delay = 8000;
        //    break;
        //  case 2:
        //    module_delay = 4000;
        //    break;
        //}
        state = 4;
        break;
      case 4:
        HAL_greenLed1Off;
        HAL_amberLed1On;
        HAL_redLed2On;
        module_delay = 2000;
        state = 5;
        break;
      case 5:
        HAL_amberLed1Off;
        HAL_redLed1On;
        HAL_redLed2On;
        module_delay = 1000;
        state = 6;
        break;
      case 6:
        HAL_redLed1On;
        HAL_redLed2On;
        HAL_amberLed2On;
        module_delay = 1000;
        state = 7;
        break;
      case 7:
        HAL_redLed1On;
        HAL_redLed2Off;
        HAL_amberLed2Off;
        HAL_greenLed2On;
        //switch (priority) {
        //  case 0:
            module_delay = 6000;
        //    break;
        //  case 1:
        //    module_delay = 4000;
        //    break;
        //  case 2:
        //    module_delay = 8000;
        //    break;
        //}
        state = 8;
        break;
      case 8:
        HAL_redLed1On;
        HAL_greenLed2Off;
        HAL_amberLed2On;
        module_delay = 2000;
        state = 1;
        break;
    }
  }
}
