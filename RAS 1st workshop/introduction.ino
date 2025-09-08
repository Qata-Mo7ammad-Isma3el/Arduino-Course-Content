/*
Our workshop topics:
 1) Arduino anatomy and definition.
 2) Arduino IDE. 
 3) Arduino Syntax and Program Flow (void setup & void loop) 
 4) pinMode()
 5) digitalWrite() && digitalRead() && analogWrite() (PWM pins) && analogRead()
 6) Breadboard
 7) simple blink code (LED)
 
 8) Arduino Serial | Serial.begin()
 9) Arduino Serial.print()
 10) Serial.available()
 11) Arduino Serial.read() and Serial.write()

*/

/*
  • What is Arduino?
    Arduino is a software as well as hardware platform that helps in making
    electronic projects. It is an open source platform and has a variety of controllers 
    and microprocessors. There are various types of Arduino boards used for various purposes.

    The Arduino is a single circuit board, which consists of different interfaces or parts. 
    The board consists of the set of digital and analog pins that are used to connect various 
    devices and components, which we want to use for the functioning of the electronic devices.
*/


/*
  • Arduino anatomy
  
  1. Microcontroller (ATmega328P): The main chip that executes your code, 
     handling all input and output signals.

  2. Digital I/O Pins (D0–D13): Pins used for digital input or output 
     (e.g., reading from a button or controlling an LED). Six of these pins 
     (3, 5, 6, 9, 10, 11) can also output PWM signals for tasks like dimming LEDs or controlling motors.

  3. Analog Input Pins (A0–A5): Pins that measure varying voltage inputs from sensors, 
     ranging from 0 to 5V. The microcontroller converts these to digital values from 0 to 1023.

  4. Power Jack: Allows for an external power source (7-12V DC). 
     This is a stable way to power the Uno when not connected to USB.

  5. USB Port: Connects the Arduino to a computer for programming and powering. 
     It also allows for serial communication with the computer.

  6. Voltage Regulator: Steps down higher voltages from the power jack to the board’s 
     operating voltage (5V), protecting components.

  7. Reset Button: Restarts the code running on the board, 
     useful when testing or troubleshooting.

  8. TX/RX LEDs: Indicators for serial communication (transmit and receive) 
     between the Arduino and the computer or other devices.

  9. Crystal Oscillator (16 MHz): Keeps timing consistent and accurate, essential 
     for operations that require precise timing.

  10. ICSP Header (In-Circuit Serial Programming): Six pins used to program the microcontroller 
      directly, without using the USB port, which can be useful for advanced projects.

  11. Power Pins:
      - 3.3V: Powers devices that need 3.3V.
      - 5V: Powers devices that need 5V.
      - GND: Provides grounding to complete circuits.
      - Vin: Allows you to supply external power directly to the board.
*/




/*
  Basic Structure
    Arduino code (also called Arduino sketch) includes two main parts: setup
    code and loop code.
*/

void setup() {
// Setup Code
  /*
  1. Is code in setup() function.
  2. Executed right after power-up or reset.
  3. Executed only one time.
  4. Used to initialize variables, pin modes, start using libraries.
  */

  // initialize digital pin (13) as an output.
  pinMode(13, OUTPUT);
}

void loop() {
// Loop Code 
  /*
  1. Is code in loop() function.
  2. Executed right after setup code.
  3. Executed repeatedly (infinitely).
  4. Used to do the main task of application.
  */


  digitalWrite(13, HIGH);       // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(13, LOW);        // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}

// important functions
/* 
  1. digitalWrite(pin, value) -> Sets the specified digital pin to either HIGH (5V) or LOW (0V).
    Example: Turning an LED on or off.

  2. digitalRead(pin) -> Reads the value from a specified digital pin, either HIGH (5V) or LOW (0V).
    Example: Checking if a button is pressed.

  3. analogWrite(pin, value) -> Writes an analog (PWM) value to a pin, which can range from 0 to 255 (for 8-bit resolution).
    Example: Controlling the brightness of an LED or the speed of a motor.
  
  4. analogRead(pin) -> Reads the analog value (voltage) from a specified pin, typically ranging from 0 to 1023 (for 10-bit resolution).
    Example: Reading data from a sensor like a potentiometer.

*/
