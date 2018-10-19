int adcs[] = {A9, A8, A7, A6, A5, A4, A3, A2, A1, A0,
              A22, A21, A20, A19, A18, A17};
int leds[] = {0, 1, 2, 3, 4, 5, 6, 7, 25, 26, 27, 28, 29, 30, 31, 32};


void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
  analogReadAveraging(32);
  for (int i = 0; i < 16; i++){
    pinMode(adcs[i], INPUT);
    pinMode(leds[i], OUTPUT);
  }
}

void read_all(){
  for (int l = 0; l < 16; l++){digitalWrite(leds[l], LOW);} // just in case
  int t = micros(); // For timing
  for (int l = 0; l < 16; l ++){
    digitalWrite(leds[l], HIGH);
    //delay_here?
    delay(1);
    int reads[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 16; i++){
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
  if (Serial.available()){
    char input = Serial.read();
    if (input == 'a'){
      read_all();
    }
  }

}

