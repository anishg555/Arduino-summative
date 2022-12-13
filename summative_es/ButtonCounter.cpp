#include "ButtonCounter.h"
#include "hal.h"
#include "Concurrent.h"

//--------------------------------------------------------------
// Constructor
// Puts class into a sane state whenever an instance of the
// class is declared.
//--------------------------------------------------------------

ButtonCounter::ButtonCounter()
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

void ButtonCounter::process()
{
  static unsigned long debounce_count;
    
      if (init_module1_clock) {
      module_delay = 15;
      module_time=millis();
      module_doStep=false;
      init_module1_clock=false;
      state = NOT_PRESSED;
    }
    else {
      unsigned long m=millis();
      if ( ( (long)(m - module_time) ) > module_delay ) {
        module_time = m; module_doStep = true;
      }
      else module_doStep = false;
    }

    if (module_doStep) {
      switch(state){
          case NOT_PRESSED: 
            if (button1Released) state = NOT_PRESSED;
            else {
              debounce_count = millis();
              state = PARTIAL_PRESS;
            }
            break;
          case PARTIAL_PRESS: 
            if (button1Released) state = NOT_PRESSED;
            else if ((millis()-debounce_count) < debounce) state = PARTIAL_PRESS;
            else state = DEBOUNCED_PRESS;
            break;
          case DEBOUNCED_PRESS: 
            if (button1Released) state = NOT_PRESSED;
            else state = DEBOUNCED_PRESS;
            break;
          
          default: 
            state = NOT_PRESSED; 
            break;
      }  
      B1_state = state;
    }
    {
    static switch_state_t   old;
    if (old != B1_state)
    {
      old = B1_state;
      switch(old)
      {
      case DEBOUNCED_PRESS:
        Serial.println("B1 = debounced");
        break;
      case PARTIAL_PRESS:
        Serial.println("B1 = de-bouncing");
        break;
      default:
        Serial.println("B1 = not pressed");
      }
    }
  }
  
  // Only process the finite state machine on a 'tick' / 'step'
  if (actionTask())
  {
      switch (state)
      {
        case 0:
            break;
      }
  }
}
