#ifndef _ButtonCounter_h_
#define _ButtonCounter_h_

#include "Concurrent.h"         // Base class


class ButtonCounter : public Concurrent {
  private:
    int state;
  public:
    void process();
    ButtonCounter();
};

#endif
