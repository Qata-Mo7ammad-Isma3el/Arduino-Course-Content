#include <LiquidCrystal.h>
//pins
int RS = 8, E = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
int PIR_pin = 3;
int long count = 0;
void setup() {
  Serial.begin(9600);
  LCD.begin(16, 2);
  pinMode(PIR_pin, INPUT);
  LCD.print("count:0");
}

void loop() {
  char buffer[15];
  if (digitalRead(PIR_pin) == HIGH) {
    LCD.clear();
    ++count;
    sprintf(buffer, "count:%d", count);
    Serial.println(buffer);
    LCD.print(buffer);
  }
 
  delay(1000);
  
}
/*
1- https://arduinogetstarted.com/tutorials/arduino-motion-sensor
*/