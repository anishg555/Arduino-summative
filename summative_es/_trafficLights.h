#ifdef WE_WANT_TO_DELETE_THIS

#ifndef _TRAFFICLIGHTS_H_
#define _TRAFFICLIGHTS_H_

#include "Concurrent.h"
#include "hal.h"

class trafficLights {
private:
    static unsigned long moduleTime, moduleDelay;
    static bool moduleStep;
    static unsigned char lightsState;
    static unsigned char priority; // 0 = equal, 1 = set 1, 2 = set 2
    bool init_module0_clock = true;
public:
    trafficLights();
    void runLights();  
};

#endif


#endif
