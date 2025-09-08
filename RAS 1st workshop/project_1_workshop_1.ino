int Red = 13, yellow = 12, Green = 11;

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(Green, OUTPUT);


  /*
    an alternative way to do the same thing. 
    you don't have to use it but it is good when you are dealing with more pins 
  for(int i=11; i<=13; i++){
    pinMode(i , OUTPUT);
  }
*/

  // and to deal with your pins with more efficient way use arrays to define your pins with pinMode()
  /*
  int arr[3]=[13 , 12 , 11];
  for(int i=0; i<=sizeof(arr)/sizeof(int); i++){
    pinMode(i , OUTPUT);
  }
*/

}

void loop() {
  digitalWrite(Green, HIGH);
  delay(1000);
  digitalWrite(Green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(Green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(Red, HIGH);
  delay(1000);
    digitalWrite(Green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(Red, LOW);
}