#define RES  16
// change HARDWARE AVG to 1, 2, 4, 8, 16, 32
#define AVG  1
#define CNT  160000 / AVG

int t;

void setup() {
  Serial.begin(115200);
  analogReadResolution(RES);
  analogReadAveraging(AVG);
  analogReference(0);

  // Take a bunch and send over serial, see time

  t = micros();
  int a0;

  for(int i = 0; i < CNT ; i++){
    a0 = analogRead(A0);             // read data
    Serial.print(a0);
  }

  t = micros() - t;
  Serial.print("ADC sampling time (total for 160000) "); Serial.print(" = ");
  Serial.print(t); Serial.println(" uS");
}


void loop() {
  //int t = micros();
  int a0;

  for(int i = 0; i < CNT ; i++){
    a0 = analogRead(A0);             // read data
  }

  //t = micros() - t;
  Serial.print("ADC sampling rate (AVG "); Serial.print(AVG); Serial.print(") = ");
  Serial.print(t); Serial.println(" kSPS");
}
