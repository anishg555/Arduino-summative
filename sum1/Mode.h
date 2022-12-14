#ifndef _MODE_H_
#define _MODE_H_

#include "Concurrent.h"

class ModeSwitch : public Concurrent {  
public:
    ModeSwitch();
    void selectMode();
    int state;
};

#endif
