/************************************************************/
/* Heartbeat.h                                             */
/*                                                          */
/* Class library for blinking the RED LED.                  */
/*                                                          */
/* ENGD2103, November 2022                                  */
/************************************************************/

#include "Heartbeat.h"
#include "hal.h"

//--------------------------------------------------------------
// Constructor
// Puts class into a sane state whenever an instance of the
// class is declared.
//--------------------------------------------------------------

Heartbeat::Heartbeat()
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

void Heartbeat::process()
{
  // Only process the finite state machine on a 'tick' / 'step'
  if (actionTask())
  {
    switch(state){
      case 0:
        PORTB |= dot;
        module_delay = 400;
        state = 1;
        break;
      case 1:
        PORTB &= ~dot;
        module_delay = 400;
        state = 0;
        break;
        
    }
  }
}
