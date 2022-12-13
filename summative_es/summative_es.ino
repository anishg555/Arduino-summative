#include "hal.h"
#include "Concurrent.h"
#include "TrafficLights.h"
#include "Heartbeat.h"
#include "ButtonCounter.h"

TrafficLights Lights;
Heartbeat Heartbeat;
ButtonCounter Counter;

void setup() {
  // put your setup code here, to run once:
  DDRD |= 0b11111100;
  DDRB |= 0b00110001;
  DDRC |= 0b00000011;
  //init_module1_clock = true;
  Serial.begin(9600);

  Lights.setRunning(true);
  Heartbeat.setRunning(true);
  Counter.setRunning(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  {
    Lights.process();
    Heartbeat.process();
    Counter.process();
  }
}
