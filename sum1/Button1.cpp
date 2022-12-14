#include "Button1.h"
#include "hal.h"
#include "Concurrent.h"

#define debounce    300

/*Default constructor*/
Button1::Button1()
{
  isRunning = false; // The button counter is deactivated by default
  module_delay = 500; // Default delay is 500ms
  button1State = 0; // The default state is
  init_module1_clock = true;
}

void Button1::process()
{
  static unsigned long debounce_count;

  {
    if (init_module1_clock) {
      module_delay = 15;
      module_time = millis();
      module_doStep = false;
      init_module1_clock = false;
      button1State = NOT_PRESSED;
    }
    else {
      unsigned long m = millis();
      if ( ( (long)(m - module_time) ) > module_delay ) {
        module_time = m; module_doStep = true;
      }
      else module_doStep = false;
    }

    if (module_doStep) {
      switch (button1State) {
        case NOT_PRESSED:
          if (button1Released) button1State = NOT_PRESSED;
          else {
            debounce_count = millis();
            button1State = PARTIAL_PRESS;
          }
          break;
        case PARTIAL_PRESS:
          if (button1Released) button1State = NOT_PRESSED;
          else if ((millis() - debounce_count) < debounce) button1State = PARTIAL_PRESS;
          else button1State = DEBOUNCED_PRESS;
          break;
        case DEBOUNCED_PRESS:
          if (button1Released) button1State = NOT_PRESSED;
          else button1State = DEBOUNCED_PRESS;
          break;

        default:
          button1State = NOT_PRESSED;
          break;
      }
      B1_state = button1State;
    }
    {
      static switch_state_t   old;
      if (old != B1_state)
      {
        old = B1_state;
        switch (old)
        {
          case DEBOUNCED_PRESS:
            Serial.println("B1 = debounced");
            break;
          case PARTIAL_PRESS:
            //Serial.println("B1 = de-bouncing");
            break;
        }
      }
    }
  }
}
