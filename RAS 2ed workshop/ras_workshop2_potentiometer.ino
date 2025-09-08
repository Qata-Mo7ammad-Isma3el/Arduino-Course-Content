/*
  • About Potentiometer
    Rotary potentiometer (also called rotary angle sensor) is used to manually adjust the value of something 
    (e.g volume of the stereo, the brightness of lamp, zoom level of oscilloscope...)
  
  • Potentiometer usually has 3 pins:
    1. GND pin: needs to be connected to GND (0V)
    2. VCC pin: needs to be connected to VCC (5V or 3.3v)
    3. Output pin: outputs the voltage to Arduino's input pin.
*/
const int LED = 6, pote = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Potentiometer_value = analogRead(pote);
  int LED_Brightness = map(Potentiometer_value , 0 , 1023 , 0 , 255);
  char buffer[50];
  sprintf(buffer , "Potentiometer:%d  LDE:%d" , Potentiometer_value , LED_Brightness);
  Serial.println(buffer);
  analogWrite(LED , LED_Brightness);
  delay(500);
}
