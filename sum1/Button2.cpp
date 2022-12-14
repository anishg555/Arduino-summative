#include "Button2.h"
#include "hal.h"
#include "Concurrent.h"

#define debounce    300

/*Default constructor*/
Button2::Button2()
{
  isRunning = false; // The button counter is deactivated by default
  module_delay = 500; // Default delay is 500ms
  button2State = 0; // The default state is
  init_module2_clock = true;
  modeState = 0;
  modeNumber = 1;
}

void Button2::process()
{
  static unsigned long debounce_count;

  {
    if (init_module2_clock) {
      module_delay = 15;
      module_time = millis();
      module_doStep = false;
      init_module2_clock = false;
      button2State = NOT_PRESSED;
    }
    else {
      unsigned long m = millis();
      if ( ( (long)(m - module_time) ) > module_delay ) {
        module_time = m; module_doStep = true;
      }
      else module_doStep = false;
    }

    if (module_doStep) {
      switch (button2State) {
        case NOT_PRESSED:
          if (button2Released) button2State = NOT_PRESSED;
          else {
            debounce_count = millis();
            button2State = PARTIAL_PRESS;
          }
          break;
        case PARTIAL_PRESS:
          if (button2Released) button2State = NOT_PRESSED;
          else if ((millis() - debounce_count) < debounce) button2State = PARTIAL_PRESS;
          else button2State = DEBOUNCED_PRESS;
          break;
        case DEBOUNCED_PRESS:
          if (button2Released) button2State = NOT_PRESSED;
          else button2State = DEBOUNCED_PRESS;
          break;

        default:
          button2State = NOT_PRESSED;
          break;
      }
      B2_state = button2State;
    }
    {
      static switch_state_t2   old;
      if (old != B2_state)
      {
        old = B2_state;
        switch (old)
        {
          case DEBOUNCED_PRESS:
            switch (modeState) {
              case 0:
                modeNumber = 2;
                modeState = 1;
                break;
              case 1:
                modeNumber = 3;
                modeState = 2;
                break;
              case 2:
                modeNumber = 4;
                modeState = 3;
                break;
              case 3:
                modeNumber = 5;
                modeState = 4;
                break;
              case 4:
                modeNumber = 1;
                modeState = 5;
                break;
              default:
                modeNumber = 1;
                modeState = 0;
            }
            break;
        }
      }
    }
  }
}
