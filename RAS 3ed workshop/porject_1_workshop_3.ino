const int Trigger_pin = 13, Echo_pin = 12;
int LED_array[] = { 7, 6, 5, 4, 3, 2 };

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(LED_array[i], OUTPUT);
  }
  pinMode(Trigger_pin, OUTPUT);
  pinMode(Echo_pin, LOW);
}

void loop() {
  int distance = Distance();
  if (distance > 272 && distance <= 330) {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], LOW);
    digitalWrite(LED_array[2], LOW);
    digitalWrite(LED_array[3], LOW);
    digitalWrite(LED_array[4], LOW);
    digitalWrite(LED_array[5], LOW);
  } else if (distance > 217 && distance <= 272) {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], HIGH);
    digitalWrite(LED_array[2], LOW);
    digitalWrite(LED_array[3], LOW);
    digitalWrite(LED_array[4], LOW);
    digitalWrite(LED_array[5], LOW);
  } else if (distance > 162 && distance <= 217) {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], HIGH);
    digitalWrite(LED_array[2], HIGH);
    digitalWrite(LED_array[3], LOW);
    digitalWrite(LED_array[4], LOW);
    digitalWrite(LED_array[5], LOW);
  } else if (distance > 107 && distance <= 162) {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], HIGH);
    digitalWrite(LED_array[2], HIGH);
    digitalWrite(LED_array[3], HIGH);
    digitalWrite(LED_array[4], LOW);
    digitalWrite(LED_array[5], LOW);
  } else if (distance > 52 && distance <= 107) {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], HIGH);
    digitalWrite(LED_array[2], HIGH);
    digitalWrite(LED_array[3], HIGH);
    digitalWrite(LED_array[4], HIGH);
    digitalWrite(LED_array[5], LOW);
  } else {
    digitalWrite(LED_array[0], HIGH);
    digitalWrite(LED_array[1], HIGH);
    digitalWrite(LED_array[2], HIGH);
    digitalWrite(LED_array[3], HIGH);
    digitalWrite(LED_array[4], HIGH);
    digitalWrite(LED_array[5], HIGH);
  }
  char buffer[15];
  sprintf(buffer, "Distance:%d cm", distance);
  Serial.println(buffer);
}

int Distance() {
  unsigned long travel_time = 0;
  int D = 0;
  digitalWrite(Trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger_pin, LOW);
  travel_time = pulseIn(Echo_pin, HIGH);
  D = (travel_time / 2) * 0.0343;
  return D;
}