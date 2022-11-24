/************************************************************/
/* hal.cpp                                                  */
/*                                                          */
/* Hardware Abstraction Layer (HAL) implementation          */
/* Anish Gautam / P2657398 / 13-10-2022                     */
/************************************************************/

#include "hal.h"

void HAL_setupGPIO()
{
  DDRD |= red_led1;
  DDRD |= red_led2;
  DDRD |= amber_led1;
  DDRD |= amber_led2;
  DDRD |= green_led1;
  DDRD |= green_led2;

  DDRC &= ~leftSwitch;
  PORTC |= leftSwitch;
  DDRC &= ~rightSwitch;
  PORTC |= rightSwitch;

  DDRB &= ~DATA;
  DDRB &= ~CLOCK;
  DDRB &= ~LATCH;
}

void HAL_toggleLatch()
{
  DDRB |= LATCH;
  DDRB &= ~LATCH;
}

void HAL_toggleClock()
{
  DDRB |= CLOCK;
  DDRB &= ~CLOCK;
}

void writeToShiftRegister(byte value)
{
  byte mask = B10000000;

  for (int i = 7; i >= 0; i--)
  {
    if (value & mask)
    {
      DDRB |= DATA;
    }
    else
    {
      DDRB &= ~DATA;
    }
    HAL_toggleClock();
    mask = mask >> 1;
  }
  HAL_toggleLatch();
}
