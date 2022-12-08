/************************************************************/
/* TrafficLights.h                                             */
/*                                                          */
/* Class library for blinking the RED LED.                  */
/*                                                          */
/* ENGD2103, November 2022                                  */
/************************************************************/

#ifndef _TrafficLights_h_
#define _TrafficLights_h_

#include "Concurrent.h"         // Base class


class TrafficLights : public Concurrent {
  public:
    void             process();
    TrafficLights();

  private:
    int              state;
};

#endif
