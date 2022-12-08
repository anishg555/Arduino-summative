/************************************************************/
/* Template.h                                             */
/*                                                          */
/* Class library for blinking the RED LED.                  */
/*                                                          */
/* ENGD2103, November 2022                                  */
/************************************************************/

#ifndef _Template_h_
#define _Template_h_

#include "Concurrent.h"         // Base class


class Template : public Concurrent {
  public:
    void             process();
    Template();

  private:
    int              state;
};

#endif
