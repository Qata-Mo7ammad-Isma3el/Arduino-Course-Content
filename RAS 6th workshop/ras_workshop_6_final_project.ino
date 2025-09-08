/*
  Pin's documentation:
  1) DC motors:

  • front left motor:
     input 1 => 13 
     input 2 => 12 
  
  • front Right motor:
     input 3 => 9
     input 4 => 8 

  • back left motor:
     input 1 => 11
     input 2 => 10 
  
  • back Right motor:
     input 3 => 7
     input 4 => 6 
  ------------------
  2) servo motor: 
   Signal pin => 5

  3) ultrasonic sensor:
   Trigg => 4
   Echo => 3

*/
#include <Servo.h>

//variables declaration
const byte FL_input_1 = 13, FL_input_2 = 12;
const byte FR_input_3 = 9, FR_input_4 = 8;
//-----------------------------------------
const byte BL_input_1 = 11, BL_input_2 = 10;
const byte BR_input_3 = 7, BR_input_4 = 6;
//-----------------------------------------
const byte servo_pin = 5;
//-----------------------------------------
const byte Trigg = 4, Echo = 3;

Servo my_servo;
void setup() {
  pinMode(FL_input_1, OUTPUT);
  pinMode(FL_input_2, OUTPUT);
  pinMode(FR_input_3, OUTPUT);
  pinMode(FR_input_4, OUTPUT);
  //-------------------------
  pinMode(BL_input_1, OUTPUT);
  pinMode(BL_input_2, OUTPUT);
  pinMode(BR_input_3, OUTPUT);
  pinMode(BR_input_4, OUTPUT);
  //-------------------------
  pinMode(Trigg, OUTPUT);
  pinMode(Echo, LOW);
  //-------------------------
  my_servo.attach(servo_pin);
  //-------------------------
  Serial.begin(9600);
  my_servo.write(90);
}

void loop() {
  float distance = Get_Distance();
  if (distance >= 200) {
    Forward(FL_input_1, FL_input_2);
    Forward(FR_input_3, FR_input_4);
    Forward(BL_input_1, BL_input_2);
    Forward(BR_input_3, BR_input_4);
  } else if (distance <= 100) {
    my_servo.write(0);
    delay(2000);
    float Right_distance = Get_Distance();

    my_servo.write(180);
    delay(2000);
    float Left_distance = Get_Distance();

    if (Right_distance >= Left_distance) {
      Forward(FL_input_1, FL_input_2);
      Backward(FR_input_3, FR_input_4);
      Forward(BL_input_1, BL_input_2);
      Backward(BR_input_3, BR_input_4);
      delay(1000);
      Forward(FL_input_1, FL_input_2);
      Forward(FR_input_3, FR_input_4);
      Forward(BL_input_1, BL_input_2);
      Forward(BR_input_3, BR_input_4);
    } else if (Right_distance <= Left_distance) {
      Backward(FL_input_1, FL_input_2);
      Forward(FR_input_3, FR_input_4);
      Backward(BL_input_1, BL_input_2);
      Forward(BR_input_3, BR_input_4);
      delay(1000);
      Forward(FL_input_1, FL_input_2);
      Forward(FR_input_3, FR_input_4);
      Forward(BL_input_1, BL_input_2);
      Forward(BR_input_3, BR_input_4);
    } else if (Right_distance == Left_distance) {
      Stop(FL_input_1, FL_input_2);
      Stop(FR_input_3, FR_input_4);
      Stop(BL_input_1, BL_input_2);
      Stop(BR_input_3, BR_input_4);
    }
    my_servo.write(90);
  }
}


void Stop(int pin_1, int pin_2) {
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
}

void Forward(int pin_1, int pin_2) {
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
}

void Backward(int pin_1, int pin_2) {
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, HIGH);
}

float Get_Distance() {
  long duration;
  float distance;

  digitalWrite(Trigg, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigg, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigg, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}
