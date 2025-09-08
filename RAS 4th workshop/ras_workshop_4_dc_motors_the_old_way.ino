/*
  • DC Motor:
    • Widely used in small toys and in robotics projects
    • Convert electrical energy in mechanical energy
    • Could not be connected directly to Arduino pin (max 25mA)
    • We need a motor driver
      • L298 H-bridge (later)
      • Simple Transistor (NPN or MOSFET) circuit
   
   to work with DC Motors you have to use diod and NPN Transistor. the DC motor require high voltage to work 
   so the 5v in the arduino won't do the job so we can use external voltage source if the DC motor is big 
   and have heavy load.
*/

// let's have a small project using one DC motor
int motor_controller_pin = 9;  //9 is PWM pin so it can work with digital and analog
void setup() {
  pinMode(motor_controller_pin, OUTPUT);
}
void loop() {

  /*digitalWrite(motor_controller_pin , HIGH);
  delay(5000);
  digitalWrite(motor_controller_pin , LOW);
  delay(1000);*/
  int speed = 50;
  analogWrite(motor_controller_pin, speed);
  delay(5000);
  analogWrite(motor_controller_pin, 0);
  delay(1000);
}
