/************************************************************/
/* hal.h                                                    */
/*                                                          */
/* Hardware Abstraction Layer (HAL) definitions             */
/* Anish Gautam / P2657398 / 13-10-2022                     */
/************************************************************/

#ifndef _HAL_H_
#define _HAL_H_

#include <Arduino.h>
#include <Wire.h>

#define red_led1          B00000100
#define amber_led1        B00001000
#define green_led1        B00010000
#define red_led2          B00100000
#define amber_led2        B01000000
#define green_led2        B10000000

#define HAL_redLed1On     PORTD |= red_led1
#define HAL_redLed1Off    PORTD &= ~red_led1

#define HAL_amberLed1On   PORTD |= amber_led1
#define HAL_amberLed1Off  PORTD &= ~amber_led1

#define HAL_greenLed1On   PORTD |= green_led1
#define HAL_greenLed1Off  PORTD &= ~green_led1

#define HAL_redLed2On     PORTD |= red_led2
#define HAL_redLed2Off    PORTD &= ~red_led2

#define HAL_amberLed2On   PORTD |= amber_led2
#define HAL_amberLed2Off  PORTD &= ~amber_led2

#define HAL_greenLed2On   PORTD |= green_led2
#define HAL_greenLed2Off  PORTD &= ~green_led2

#define HAL_millis        millis();

void HAL_setupGPIO();

#define leftSwitch            B00000001
#define rightSwitch           B00000010

#define button1Released       (PINC & leftSwitch)
#define button1Pressed        !button1Released

#define button2Released       (PINC & rightSwitch)
#define button2Pressed        !button2Released

#define LATCH                 B00100000
#define CLOCK                 B00010000
#define DATA                  B00000001

#define A                     B00000001
#define B                     B00000010
#define C                     B00000100
#define D                     B00001000
#define E                     B00010000
#define F                     B00100000
#define G                     B01000000
#define dot                   B10000000

#define char0                 (A|F|E|D|C|B)
#define char1                 (B|C)
#define char2                 (A|B|G|E|D)
#define char3                 (A|B|G|C|D)
#define char4                 (F|G|B|C)
#define char5                 (A|F|G|C|D)
#define char6                 (A|F|G|C|D|E)
#define char7                 (A|B|C)
#define char8                 (A|B|C|D|E|F|G)
#define char9                 (A|B|C|D|F|G)
#define charA                 (E|F|A|B|C|G)
#define charB                 (F|E|D|C|G)
#define charC                 (A|F|E|D)
#define charD                 (B|G|E|D|C)
#define charE                 (A|F|G|E|D)
#define charF                 (A|F|G|E)

void HAL_toggleLatch();

void writeToShiftRegister(byte value);

#define MPU_6050              0x68
#define PWR_MGMT_1            0x6B
#define XOUT_High             0X3B
#define YOUT_High             0x3D
#define ZOUT_High             0x3F

#define accCharU              (A|B|C|E|F)
#define accCharF              charF
#define accCharB              charB
#define accCharL              (D|E|F)
#define accLeft               (F|A)
#define accRight              (G|F)

#endif
