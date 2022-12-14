#include "Template.h"
#include "hal.h"

Template::Template()
{
  isRunning = false;
  module_delay = 500;
  state = 0;
}

void Template::process()
{
  // Only process the finite state machine on a 'tick' / 'step'
  if (actionTask())
  {

  }
}
