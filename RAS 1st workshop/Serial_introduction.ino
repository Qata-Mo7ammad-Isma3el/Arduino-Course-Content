/*
  About Serial Monitor

  Serial Monitor is one of the tools in Arduino IDE. It is used for two purposes:

    • Arduino → PC: Receives data from Arduino and display data on screen. 
      This is usually used for debugging and monitoring

    • PC → Arduino: Sends data (command) from PC to Arduino.

  Data is exchanged between Serial Monitor and Arduino via USB cable, 
  which is also used to upload the code to Arduino. Therefore, to use Serial Monitor,
  we MUST connect Arduino and PC via this cable.
*/


/* 
  Baud rate selection: select communication speed (baud rate) between Arduino and PC. 
  This value MUST be the same as the value used in Arduino code (in Serial.begin() function).
*/

const int LED = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  const int baudrate = 9600;
  /*
  • Arduino To PC
    To send data from Arduino to PC, we need to use the following Arduino code:
    Set baud rate and begin Serial port by using Serial.begin() function.
 */
  Serial.begin(baudrate);

  /*
 Send data to Serial Monitor using one of the following functions: 
 Serial.print(), Serial.println(), Serial.write(). 
 For example, send "Hello World!" to Serial Monitor
 */
  Serial.println("Hello World!");
}


/*
  • PC To Arduino

  How to send data from PC to Aduino and read it on Arduino You will 
  type text on Serial Monitor and then click Send button.
  
  Arduino reads data and process it. To read data, we need to use the following Arduino code: 
    1. Set baud rate and begin Serial port. 
    2. Check whether data is available or not.
    3. Read data from Serial port using one of the following functions: 
      Serial.read(), Serial.readBytes(), Serial.readBytesUntil(), Serial.readString(), Serial.readStringUntil().
 */



void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // TODO
    String command = Serial.readStringUntil('\n');
    if (command == "ON") {
      digitalWrite(LED, HIGH);     // turn on LED
      Serial.println("LED is turned ON");  // send action to Serial Monitor
    } else if (command == "OFF") {
      digitalWrite(LED, LOW);       // turn off LED
      Serial.println("LED is turned OFF");  // send action to Serial Monitor
    }
  }
}
