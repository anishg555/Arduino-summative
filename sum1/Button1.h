#ifndef _Button1_h_
#define _Button1_h_

#include "Concurrent.h"

/*Button counter class, inherited from Concurrent*/
class Button1 : public Concurrent {
  private:
    int button1State;
    bool init_module1_clock;
    
    typedef enum
    {
      NOT_PRESSED,
      PARTIAL_PRESS,
      DEBOUNCED_PRESS
    } switch_state_t;

    switch_state_t    B1_state;
    
  public:
    void process();
    Button1();
};

#endif
