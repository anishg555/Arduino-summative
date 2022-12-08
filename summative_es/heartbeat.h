#ifndef _Heartbeat_h_
#define _Heartbeat_h_

#include "Concurrent.h"         // Base class


class Heartbeat : public Concurrent {
  public:
    void             process();
    Heartbeat();

  private:
    int              state;
};

#endif
