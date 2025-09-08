int temp_pin = A0;
int R_pin = 11, B_pin = 10, G_pin = 9;


void setup() {
  Serial.begin(9600);
  // pinMode(R_pin, OUTPUT);
  // pinMode(B_pin, OUTPUT);
  // pinMode(G_pin, OUTPUT);
  for (int i = 9; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int temp_reading = analogRead(temp_pin);

  char buffer[20];
  sprintf(buffer, "Analog Reading:%d", temp_reading);
  Serial.println(buffer);
  int Red_value = map(temp_reading, 20, 385, 0, 255);
  int Green_value = map(temp_reading, 20, 385, 0, 255);
  int blue_value = map(temp_reading, 20, 385, 0, 255);
  set_Color(Red_value, Green_value+100, blue_value+200);
}


void set_Color(int R_value, int G_value, int B_value) {
  analogWrite(R_pin, R_value);
  analogWrite(B_pin, G_value);
  analogWrite(G_pin, B_value);
}