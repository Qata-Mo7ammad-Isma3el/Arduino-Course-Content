void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j <= i; j++)
      Serial.print('*');
    Serial.print('\n');
  }

  Serial.println("------------------------------");

  // i will draw some interesting shapes

  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j <= i; j++)
      Serial.print('*');
    Serial.print('\n');
  }

  Serial.println("------------------------------");

  for (int i = 0; i < 7; i++) {
    for (int j = 6; j >= i + 1; j--)
      Serial.print(" ");
    for (int k = 0; k <= i; k++)
      Serial.print('*');
    Serial.print('\n');
  }

  Serial.println("------------------------------");
  for (int i = 0; i < 7; i++) {
    for (int j = 1; j <= i; j++)
      Serial.print(" ");
    for (int k = 7; k > i; k--)
      Serial.print('*');
    Serial.print('\n');
  }

  // my favorite way is to use external counters
  Serial.println("------------------------------");
  int external_1 = 5, external_2 = 1;
  for (int i = 1; i <= 7; i++) {
    for (int j = i; j <= 3; j++)
      Serial.print(" ");
    for (int k = 1; k <= external_2; k++) {
      if (external_2 <= 7)
        Serial.print('*');
    }

    if(i > 4){
      for (int j = 5; j <= i; j++)
        Serial.print(" ");
      for (int k = 1; k <= external_1; k++) {
        if (external_1 >= 1) 
          Serial.print('*');
      }
    }

    if (i > 4) external_1 -= 2;
    external_2 += 2;
    Serial.println();
  }
}

void loop() {
}
