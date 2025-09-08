/*
 • About PIR
    HC-SR501 PIR sensor is a sensor that can detect the motion of humans (or animals).
    It's widely used to detect the presence of humans in many applications (automatically turning 
    ON/OFF light bulb, opening/closing the door, activating/deactivating escalator, detecting an intruder...).


 • The HC-SR501 motion sensor has 3 pins:
  
  GND pin: needs to be connected to GND (0V)
  VCC pin: needs to be connected to VCC (5V)
  OUTPUT pin: is an output pin: LOW when no motion is detected, HIGH when motion is detected.
   This pin needs to be connected to Arduino's input pin.
*/


const int PIR = 2, LED = 3;  // the pin that OUTPUT pin of sensor is connected to
int pinStateCurrent = LOW;   // current state of pin
int pinStatePrevious = LOW;  // previous state of pin

void setup() {
  Serial.begin(9600);   // initialize serial
  pinMode(PIR, INPUT);  // set arduino pin to input mode to read value from OUTPUT pin of sensor
  pinMode(LED , OUTPUT);
}

void loop() {
  pinStatePrevious = pinStateCurrent;  // store old state
  pinStateCurrent = digitalRead(PIR);  // read new state

  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {  // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
    digitalWrite(LED , HIGH);
    // TODO: turn on alarm, light or activate a device ... here
  } else if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {  // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
    digitalWrite(LED , LOW);
    // TODO: turn off alarm, light or deactivate a device ... here
  }
}
