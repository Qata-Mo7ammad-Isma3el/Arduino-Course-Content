#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

int RS = 9, E = 8, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
//----------------------------------------------
const byte Servo_pin = 3;
Servo servo;
//----------------------------------------------
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte Row_pins[ROWS] = { 13, 12, 11, 10 };
byte cols_pins[COLS] = { A0, A1, A2, A3 };
Keypad keypad = Keypad(makeKeymap(keys), Row_pins, cols_pins, ROWS, COLS);
//------------------------------------------------------------------
String PassWord = "1234";
String Pass_in = "";
void setup() {
  LCD.begin(16, 2);
  servo.attach(Servo_pin);
  Serial.begin(9600);
  LCD.print("press # to open!");
  LCD.setCursor(0, 1);
  servo.write(0);
}
void loop() {
  char get_key = keypad.getKey();
  if (get_key) {
    if (get_key == '#') {
      if (PassWord == Pass_in) {
        servo.write(180);
        LCD.clear();
        LCD.print("Unlock!!!");
      }
    }
    Serial.println("*");
    LCD.print("*");
    Pass_in.concat(get_key);
  }
}
