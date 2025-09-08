/*
3.1) Ultrasonic Sensor && buzzer 
3.2) PIR Motion Sensor && LED light
3.3) analog Joystick && LCD 
*/

/*
  • The HC-SR04 ultrasonic sensor uses sonar to determine distance to an
  object (2cm-400cm)
    • Emitting sound waves at a frequency too high for humans to hear.
    • Wait for the sound to be reflected back
    • Calculating distance based on the time required
    • Distance =(Travel time/2) * Speed of sound
    • Speed of sound 343 m/s (0.0343 cm/us)
*/

/*
  How it works
    1. Micro-controller: generates a 10-microsecond pulse on the TRIG pin.
    
    2. The ultrasonic sensor automatically emits the ultrasonic waves.
    
    3. The ultrasonic wave is reflected after hitting an obstacle.
    
    4. The ultrasonic sensor:
      • Detects the reflected ultrasonic wave.
      • Measures the travel time of the ultrasonic wave.
    
    5. Ultrasonic sensor: generates a pulse to the ECHO pin. The duration of 
    the pulse is equal to the travel time of the ultrasonic wave.
    
    6. Micro-controller measures the pulse duration in the ECHO pin, 
    and then calculates the distance between the sensor and obstacle.
*/



const byte Trigger_pin = 3, Echo_pin = 2, piezo_pin = 10;
unsigned long travel_time = 0;
int Distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Trigger_pin, OUTPUT);
  pinMode(Echo_pin, LOW);
  pinMode(piezo_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(Trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger_pin, LOW);
  travel_time = pulseIn(Echo_pin, HIGH);
  Distance = (travel_time / 2) * 0.0343;
  //------------------------------------------
  (Distance >= 20) ? noTone(piezo_pin) : tone(piezo_pin, 540);
  char buffer[15];
  sprintf(buffer , "Distance:%d cm" , Distance);
  Serial.println(buffer);
  delay(50);
}

/*
1- https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor
2- https://arduinogetstarted.com/reference/arduino-delaymicroseconds
3- https://arduinogetstarted.com/reference/pulsein
4- https://arduinogetstarted.com/reference/notone 
5- https://arduinogetstarted.com/reference/tone
*/