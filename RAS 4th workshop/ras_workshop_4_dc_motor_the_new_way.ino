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

/*
  How It Works

    When you buy a DC motor, you need to know what voltage DC motor work. 
    Let's take a 12V DC motor as an example.

    When you power the 12V DC motor by a 12V power source:

      • 12V and GND to the positive wire and negative wire, respectively: the DC motor 
      rotates at maximum speed in one direction
    
      • 12V and GND to the negative wire and positive wire, respectively: the DC motor 
      rotates at maximum speed in the opposite direction

    As described above, when the power pole is swapped between two wires of the DC motor, 
    the rotating direction is reversed. This method is used to control the direction of the DC motor. 
    Of course, not by changing manually but by programming. 

    If we provide power to DC motors below 12V, the motor still rotates but not at maximum speed. 
    It means if we change the voltage of the power supply, we can change the speed of the DC motor. 
    However, this method is not used in practice because of the difficulty in controlling the voltage of 
    the power source. Instead, we fix the voltage of the power source and control the speed of the DC motor 
    via a PWM signal. The more duty cycle the PWM is, the higher speed the DC motor rotates.
*/

/*
  How to control DC motor using Arduino

    Controlling DC motor includes two factors: speed and direction. Arduino can 
    generate the PWM signal. However, this PWM signal has low voltage and current, 
    We cannot use it to control the DC motor. We need to use a hardware driver in between Arduino 
    and DC motor. The driver does two works:   
      • Amplify the PWM signal from Arduino (current and voltage) → for speed control
      • Receive the control signal from Arduino to swap pole of power supply → for direction control.
*/


/*
  There are many kinds of the chip, modules (e.g. L293D, L298N) can be used as
  DC motor drivers. In this tutorial, we will use the L298N driver.
  
  let's take a look first at L293D at tinkercad: 
    The L293D is a popular dual H-bridge motor driver IC that allows you to control 
    the speed and direction of two DC motors or one stepper motor. Here’s a summary of its 
    pins and functions:

 • Pin Summary:
    1. Enable 1&2 : This pin enables and controls the output for channels 1 and 2 
       (motor 1). When HIGH, the first motor is operational; when LOW, the first motor is disabled.
    2. Input 1: Controls the state of Output 1. Logic HIGH makes Output 1 HIGH, 
       and logic LOW makes it LOW.
    3. Output 1: Connects to one terminal of the first motor.
    4. GND: Ground pin.
    5. GND: Additional ground pin.
    6. Output 2: Connects to the second terminal of the first motor.
    7. Input 2: Controls the state of Output 2. Logic HIGH makes Output 2 HIGH, 
       and logic LOW makes it LOW.
    8. power 2: Supply voltage for the motors (can be up to 36V).
    
    
    9. Enable 3&4: This pin enables and controls the output for channels 3 and 4 (motor 2). 
       Similar to Pin 1, when HIGH, the second motor is enabled; when LOW, it is disabled.
    10. Input 3: Controls the state of Output 3.
    11. Output 3: Connects to one terminal of the second motor.
    12. GND: Ground pin.
    13. GND: Additional ground pin.
    14. Output 4: Connects to the second terminal of the second motor.
    15. Input 4: Controls the state of Output 4.
    16. Power 1: Logic voltage supply for the IC (usually 5V).

 Key Points:
- (Power 2) is used for the motor power supply and can handle higher voltages (up to 36V).
- (Power 1) is for the logic voltage supply and typically needs to be 5V.
- GND Pins (4, 5, 12, 13) should be connected to the ground of your power supply.

The L293D allows you to control the speed and direction of connected motors using the input pins (2, 7, 10, 15) in 
combination with the enable pins (1, 9).
*/

#include <LiquidCrystal.h>
//pins
int RS = 9, E = 8, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);

int enable = 13, input_3 = 12, input_4 = 11;
int push = 10, pot = A0;
int speed;
bool control_1, control_2;

void setup() {
  pinMode(enable, OUTPUT);
  pinMode(input_3, OUTPUT);
  pinMode(input_4, OUTPUT);
  pinMode(push, INPUT);
  LCD.begin(16, 2);
  control_1 = HIGH;
  control_2 = LOW;
  LCD.print("IEEE RAS BAU");
}

void loop() {
  // speed = map(analogRead(pot), 0, 1023, 0, 255);
  // if (digitalRead(push) == HIGH) {
  //   control_1 = LOW;
  //   control_2 = HIGH;
  //   LCD.setCursor(0, 0);
  //   LCD.print("Opposite.");
  //   LCD.setCursor(0, 1);
  //   LCD.print("Speed:");
  //   LCD.print(speed);
  //   digitalWrite(input_3, control_1);
  //   digitalWrite(input_4, control_2);
  //   analogWrite(enable, speed);
  // } else {
  //   control_1 = HIGH;
  //   control_2 = LOW;
  //   LCD.setCursor(0, 0);
  //   LCD.print("Same.");
  //   LCD.setCursor(0, 1);
  //   LCD.print("Speed:");
  //   LCD.print(speed);
  //   digitalWrite(input_3, control_1);
  //   digitalWrite(input_4, control_2);
  //   analogWrite(enable, speed);
  // }
  // delay(100);
  // LCD.clear();
}
