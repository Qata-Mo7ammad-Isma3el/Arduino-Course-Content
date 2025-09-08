/*
1) Arduino Functions
2) RGB code (analogWrite()) 


3) analog pins && analogRead()
4) LM35 temperature sensor (example)

5) add a pushbutton to the RGB code (digitalRead()) 

6) potentiometer && map() 

*/


/*
  Recap: function signature
    return-value-type function-name(parameter list){
       declarations and statements 
    }
*/

// recall : 
/* 
 analogWrite(pin, value) -> Writes an analog (PWM) value to a pin, 
 which can range from 0 to 255 (for 8-bit resolution). 
*/

/*
  • How it works

    In the nature of physics, a color is composed of three color values: 
    Red (R), Grean (G) and Blue (B). Each color value ranges from 0 to 255.

    The mix of three values creates 256 x 256 x 256 colors in total.

    If we provide PWM signals (with duty cycle from 0 to 255) to R, G, B pins, 
    we can makes RGB LED displays any color we want.

    The duty cycle of PWM signals to R, G and B pins correspond to color 
    values of Red (R), Grean (G) and Blue (B).
*/
#include <stdlib.h>
const int R = 11 , B = 10 , G = 9;
const int push_button = 7;  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(R , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(B , OUTPUT);
 //--------------------------------------------------------
 /*
  To make it easy for beginners, this tutorial uses the simplest method: initializes the
  Arduino pin as an internal pull-up input without using the external resistor. The beginners
  do NOT need to care about how to wire the pull-up/pull-down resistor. The beginners just
  need to use the Arduino code.
*/
 pinMode(push_button , INPUT_PULLUP);

//--------------------------------------------------------

  analogWrite(R,   0);
  analogWrite(G, 151);
  analogWrite(B,  157);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(push_button));
  if(digitalRead(push_button) == HIGH){
    set_Color(255 , 255 , 255);
  }else{
    setRandom_Color();
  }
  delay(500);
}


void set_Color(int R_value, int G_value, int B_value) {
  analogWrite(R,   R_value);
  analogWrite(G, G_value);
  analogWrite(B,  B_value);
}

void setRandom_Color(){
  analogWrite(R,   random(0, 255));
  analogWrite(G, random(0, 255));
  analogWrite(B,  random(0, 255));
}



