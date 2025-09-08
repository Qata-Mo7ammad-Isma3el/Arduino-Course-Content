/*
4) analog pins && analogRead()
5) LM35 temperature sensor (example)
*/

/*
  analog signals vs digital signals
   digital signals: 2 values , "HIGH" and "LOW" or 0v and 5v
   analog signals: any value between 0v and 5v

   Analog pins on Arduino can read an analog voltage and convert it to a number
    • Arduino has an ADC with a resolution of 10bit
    • This means the analog values between OV and 5V could be expressed as
      values between O and 1023 (2^10-1)
    
    conversion formula => value = (vin * 1023)/5
      analog       value   
        0v     =>    0
        2.5v   =>   511 
        5v     =>   1023
    analog pins in the arduino board are => A0 , A1 , A2 , A3 , A4 , A5 
    analog pins are always used to read data and they don't require to be 
    defined using pinMode() function cause they are INPUT pins only
*/

/*
  • Recall: 
    analogRead(pin) ->  Reads the analog value (voltage) from a specified pin, 
    typically ranging from 0 to 1023 (for 10-bit resolution).
*/

/*
  • Temperature measurement:
    • Use of TMP36, temperature sensor
    • Connection to analog pin
    we will use TMP36 this kind of sensors can measure a temperature from -50 to 125 in celsius
    the arduino will receive a voltage value in analog form (0 , 1023) 
    in order to convert it you must use conversion formula => value = (vin * 1023)/5
      analog       value   
        0v     =>    0
        2.5v   =>   511 
        5v     =>   1023

    the sensor have 3 terminals power(operating voltage 2.7v - 5.5v) , Vout (analog pin) , GND(0v) 
*/

const int temp = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp_value = analogRead(temp);
  Serial.print("Temperature:"); 
  Serial.println(temp_value); 
}
