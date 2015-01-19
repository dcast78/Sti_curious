// DualMotorShield.pde
// -*- mode: C++ -*-
//
// Shows how to run 2 simultaneous steppers
// using the Itead Studio Arduino Dual Stepper Motor Driver Shield
// model IM120417015
// This shield is capable of driving 2 steppers at
// currents of up to 750mA
// and voltages up to 30V
// Runs both steppers forwards and backwards, accelerating and decelerating
// at the limits.
//
// Copyright (C) 2014 Mike McCauley
// $Id: $
#include <AccelStepper.h>
// The X Stepper pins
#define STEPPER1_DIR_PIN 10
#define STEPPER1_STEP_PIN 11
// The Y stepper pins
#define STEPPER2_DIR_PIN 7
#define STEPPER2_STEP_PIN 6
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN);
AccelStepper stepper2(AccelStepper::DRIVER, STEPPER2_STEP_PIN, STEPPER2_DIR_PIN);
int val=0;
int x=0;
int minimo=1023;
int massimo=0;
void setup()
{
Serial.begin(115200);
pinMode(5,OUTPUT);  
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
stepper1.setMaxSpeed(1000000.0);
stepper1.setAcceleration(10000.0);
stepper1.moveTo(5000);
}
void loop()
{
// Change direction at the limits
if (stepper1.distanceToGo() == 0)
stepper1.moveTo(-stepper1.currentPosition());
stepper1.run();
val = analogRead(A4);
if (val<minimo) {
  minimo=val;
}  
if (val>massimo) {
  massimo=val;
}
Serial.print(minimo);
Serial.print(" - ");
Serial.print(val);
Serial.print(" - ");
Serial.println(massimo);
}

