
/*
  • LCD:
  • Arduino Library for HD44780 driver
  • LCD 16x2:
    • GND: connect to ground
    • vcc: +5V
    • VO: Control the contrast (Potentiometer)
    • RS: Re ister select, that controls where in the LCD's memory you're writing data to. Connect
    to digi al pin on Arduino
    • R/W: Read/ Write mode. For Writing connect to ground!
    • E: Enable writing to register. Connect to digital pin on Arduino
    • DO-D8: The bits that you're writing to a register. Connect 4 of them to digital pin on Arduino
    (4bit mode)
    • LED+: Anode of the backlight LED. Connect with resistor to +5V
    • LED-: Cathode of the backlight LED. Connect to ground.
*/

/*
  Pin	  Name	     Description
  1	    VSS	       Pin used for grounding the LCD
  2	    VDD	       Pin used for connecting voltage supply with LCD
  3	    V0	       Pin used for controlling the brightness of the display module
  4	    RS	       Pins for selection of data and command register
  5	    RW	       Pin for using the write register of LCD
  6	    E	         Pin used for sending the data to the data pins of LCD
  7-14	D0-D7	     Data pins of the LCD
  15	  A/LED+	   Anode for the backlight of LCD
  16	  K/LED-	   Cathode for the backlight of LCD
*/
/*
  connections:
    • VSS/GND => 0v GND
    • VDD/vcc => 5v
    • V0	=> Wiper of the potentiometer
    • RS => digital pin (8)
    • RW => 0v GND
    • E	=> digital pin (9)
    • D0-D7	=> digital pin (D4 pin (4) , D5 pin (5) , D6 pin (6) , D7 pin (7) )
    • A/LED+ =>  5v with resistor of 220 ohm 
    • K/LED- => 0v GND
• 
*/

/*
  • About analog Joystick
  
    You probably see the Joystick somewhere such as a game controller, toy controller, 
    or even a big real machine such as an excavator controller.
    
    The joystick is composed of two potentiometers square with each other, and one push button. 
    Therefore, it provides the following outputs:   

    • An analog value (from 0 to 1023) corresponding to the horizontal position (called X-coordinate)
    • An analog value (from 0 to 1023) corresponding to the vertical position (called Y-coordinate)
    • A digital value of a pushbutton (HIGH or LOW)
    
    The combination of two analog values can create 2-D coordinates with the center are values 
    when the joystick is in the rest position. The real direction of the coordinates can be 
    identified simply when you run a test code (in the next part).

Some applications may use all three outputs, some applications may use some of three outputs.
*/

#include <LiquidCrystal.h>
//pins
int RS = 8, E = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
#define Y_axis A0  // analog pin
#define X_axis A1  // analog pin
#define SW_pin 3   // digital pin

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  LCD.begin(16 , 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  char buffer1[16] , buffer2[16];
  int X = analogRead(X_axis);
  int Y = analogRead(Y_axis);
  int push = digitalRead(SW_pin);
  LCD.setCursor(0, 0);
  sprintf(buffer1, "X:%d  Y:%d", X, Y);
  LCD.print(buffer1);

  LCD.setCursor(0, 1);
  sprintf(buffer2, "SLC:%d", push);
  LCD.print(buffer2);

  delay(500);
  LCD.clear();
}
