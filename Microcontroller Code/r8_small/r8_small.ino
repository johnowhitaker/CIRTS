int adcs[] = {A0, A1, A2, A5, A6, A7, A4, A3};
int leds[] = {12, 11, 10, 7, 6, 5, 8, 9};


void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
  analogReadAveraging(32);
  for (int i = 0; i < 8; i++){
    pinMode(adcs[i], INPUT);
    pinMode(leds[i], OUTPUT);
  }
}

void read_all(){
  for (int l = 0; l < 8; l++){digitalWrite(leds[l], LOW);} // just in case
  int t = micros(); // For timing
  for (int l = 0; l < 8; l ++){
    digitalWrite(leds[l], HIGH);
    //delay_here?
//    delay(1);
    int reads[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 8; i++){
      reads[i] = analogRead(adcs[i]);
      Serial.print(reads[i]);
      Serial.print(',');
    }
    Serial.print('A');
    digitalWrite(leds[l], LOW);
  }
  t = micros()-t;
  Serial.println(t);
}

void loop()
{
//  digitalWrite(leds[0], HIGH);
//  digitalWrite(leds[7], LOW);
//  delay(1000);
//  digitalWrite(leds[1], HIGH);
//  digitalWrite(leds[0], LOW);
//  delay(1000);
//  digitalWrite(leds[2], HIGH);
//  digitalWrite(leds[1], LOW);
//  delay(1000);
//  digitalWrite(leds[3], HIGH);
//  digitalWrite(leds[2], LOW);
//  delay(1000);
//  digitalWrite(leds[4], HIGH);
//  digitalWrite(leds[3], LOW);
//  delay(1000);
//  digitalWrite(leds[5], HIGH);
//  digitalWrite(leds[4], LOW);
//  delay(1000);
//  digitalWrite(leds[6], HIGH);
//  digitalWrite(leds[5], LOW);
//  delay(1000);
//  digitalWrite(leds[7], HIGH);
//  digitalWrite(leds[6], LOW);
//  delay(1000);
  if (Serial.available()){
    char input = Serial.read();
    if (input == 'a'){
      read_all();
    }
    if (input == 'b'){
      digitalWrite(leds[0], HIGH);
    }
  }

}

