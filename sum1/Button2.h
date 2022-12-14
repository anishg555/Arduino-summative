#ifndef _Button2_h_
#define _Button2_h_

#include "Concurrent.h"

/*Button counter class, inherited from Concurrent*/
class Button2 : public Concurrent {
  private:
    int button2State;
    bool init_module2_clock;
    
    typedef enum
    {
      NOT_PRESSED,
      PARTIAL_PRESS,
      DEBOUNCED_PRESS
    } switch_state_t2;

    switch_state_t2    B2_state;
    
  public:
    void process();
    Button2();
    int modeState;
};

#endif
