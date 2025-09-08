int redPot = A0;    // Potentiometer for red
int bluePot = A1;   // Potentiometer for blue
int greenPot = A2;  // Potentiometer for green

int redPin = 11;   // Red pin on RGB LED
int bluePin = 10;  // Blue pin on RGB LED
int greenPin = 9;  // Green pin on RGB LED

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int redValue = map(analogRead(redPot), 0, 1023, 0, 255);
  int greenValue = map(analogRead(greenPot), 0, 1023, 0, 255);
  int blueValue = map(analogRead(bluePot), 0, 1023, 0, 255);
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  char buffer[30];
  sprintf(buffer,"Red:%d  Green:%d  Blue:%d" , redValue , greenValue , blueValue);
  Serial.println(buffer);
  delay(10);
}
