/************************************************************/
/* hal.cpp                                                  */
/*                                                          */
/* Hardware Abstraction Layer (HAL) implementation          */
/* Anish Gautam / P2657398 / 13-10-2022                     */
/************************************************************/

#include "hal.h"

void HAL_setupGPIO()
{
//  DDRD |= red_led1;
//  DDRD |= red_led2;
//  DDRD |= amber_led1;
//  DDRD |= amber_led2;
//  DDRD |= green_led1;
//  DDRD |= green_led2;
//
//  DDRC &= ~leftSwitch;
//  PORTC |= leftSwitch;
//  DDRC &= ~rightSwitch;
//  PORTC |= rightSwitch;
//
  DDRB &= ~DATA;
  DDRB &= ~CLOCK;
  DDRB &= ~LATCH;
}

//void HAL_buttonPressed()
//{
//    { // module 1
//    static unsigned long module_time, module_delay;
//    static unsigned long debounce_count;
//    static bool module_doStep;
//    static switch_state_t state; // state variable for module 0
//    
//    if (init_module1_clock) {
//      module_delay = 15;
//      module_time=millis();
//      module_doStep=false;
//      init_module1_clock=false;
//      state = NOT_PRESSED;
//    }
//    else {
//      unsigned long m=millis();
//      if ( ( (long)(m - module_time) ) > module_delay ) {
//        module_time = m; module_doStep = true;
//      }
//      else module_doStep = false;
//    }
//
//    if (module_doStep) {
//      switch(state){
//          case NOT_PRESSED: 
//            if (button1Released) state = NOT_PRESSED;
//            else {
//              debounce_count = millis();
//              state = PARTIAL_PRESS;
//            }
//            break;
//          case PARTIAL_PRESS: 
//            if (button1Released) state = NOT_PRESSED;
//            else if ((millis()-debounce_count) < debounce) state = PARTIAL_PRESS;
//            else state = DEBOUNCED_PRESS;
//            break;
//          case DEBOUNCED_PRESS: 
//            if (button1Released) state = NOT_PRESSED;
//            else state = DEBOUNCED_PRESS;
//            break;
//          
//          default: 
//            state = NOT_PRESSED; 
//            break;
//      }  
//      B1_state = state;
//    }
//  }
//    
//  {
//    static switch_state_t   old;
//    if (old != B1_state)
//    {
//      old = B1_state;
//      switch(old)
//      {
//      case DEBOUNCED_PRESS:
//        Serial.println("B1 = debounced");
//        break;
//      case PARTIAL_PRESS:
//        Serial.println("B1 = de-bouncing");
//        break;
//      default:
//        Serial.println("B1 = not pressed");
//      }
//    }
//  }
//}

void HAL_toggleLatch()
{
  PORTB |= LATCH;
  PORTB &= ~LATCH;
}

void HAL_toggleClock()
{
  PORTB |= CLOCK;
  PORTB &= ~CLOCK;
}

void writeToShiftRegister(byte value)
{
  byte mask = B10000000;

  for (int i = 7; i >= 0; i--)
  {
    if (value & mask)
    {
      PORTB |= DATA;
    }
    else
    {
      PORTB &= ~DATA;
    }
    HAL_toggleClock();
    mask = mask >> 1;
  }
  HAL_toggleLatch();
}
