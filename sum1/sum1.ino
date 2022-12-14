#include "hal.h"
#include "Concurrent.h"
#include "TrafficLights.h"
#include "Heartbeat.h"
#include "Button1.h"
#include "Button2.h"
#include "Accel.h"

#include <Wire.h>
#include <Arduino.h>

/*Class member creation*/
TrafficLights Lights;
Heartbeat Heartbeat;
Button1 LeftButton;
Button2 RightButton;
Accel Gyro;

void setup() {
  /*Sets the pins to be input or outputs*/
  DDRD |= 0b11111100;
  DDRB |= 0b00110001;
  DDRC |= 0b00000011;
  DDRC &= 0b00110000;

  /*Activates serial monitor*/
  Serial.begin(9600);

  /*Start tunning the classes*/
  Lights.setRunning(true);
  Heartbeat.setRunning(true);
  LeftButton.setRunning(true);
  RightButton.setRunning(true);
  Gyro.setRunning(true);

  /*Sets up the accelerometer*/
  Wire.begin();
  Wire.beginTransmission(MPU_6050);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  {
    /*Ties the accelerometer input and traffic light priority together*/
    Lights.priority = Gyro.lightPriority;

    Lights.process();
    Heartbeat.process();
    RightButton.process();
    LeftButton.process();
    Gyro.process();
    writeToShiftRegister(Heartbeat.heartbeatInput | Gyro.accelInput);
  }
}
