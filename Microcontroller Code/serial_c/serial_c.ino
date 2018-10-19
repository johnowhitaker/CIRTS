int sa = 1;
int da = 0;
int sb = 3;
int db = 2;

int led = 13;
int led2 = 20;

int adc = A9;


int DT = 10; //delay time when stepping - dictates max speed

int pos_a = 0;
int pos_b = 0;

void setup()
{
  Serial.begin(115200); // USB is always 12 Mbit/sec
  pinMode(sa, OUTPUT);
  pinMode(da, OUTPUT);
  pinMode(sb, OUTPUT);
  pinMode(db, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(adc, INPUT);
}


void step_a(int n){
  if (n>0){
    digitalWrite(da, LOW);
  }
  else {
    digitalWrite(da, HIGH);
    n = -n;
  }

  while (n > 0){
    digitalWrite(sa, HIGH);
    delay(DT);
    digitalWrite(sa, LOW);
    delay(DT);
    n -= 1;
  }
}

void step_b(int n){
  if (n>0){
    digitalWrite(db, LOW);
  }
  else {
    digitalWrite(db, HIGH);
    n = -n;
  }

  while (n > 0){
    digitalWrite(sb, HIGH);
    delay(DT);
    digitalWrite(sb, LOW);
    delay(DT);
    n -= 1;
  }
}


void loop()
{

  if (Serial.available()){
    char input = Serial.read();
    if (input == 'a'){
      Serial.println("STEP A ccw");
      step_a(1);
    }
    if (input == 'A'){
      Serial.println("STEP A cw");
      step_a(-1);
    }
    if (input == 'b'){
      Serial.println("STEP B ccw");
      step_b(1);
    }
    if (input == 'B'){
      Serial.println("STEP B cw");
      step_b(-1);
    }
    if (input == 'C'){
      Serial.println("STEP A ccw by 10");
      step_a(10);
    }
    if (input == 'D'){
      Serial.println("STEP B ccw by 50");
      step_b(50);
    }
    if (input == 'E'){
      Serial.println(analogRead(adc));
    }
    if (input == 'F'){
      digitalWrite(led, HIGH);
      digitalWrite(led2, HIGH);
      Serial.print("LED ON: ");
      Serial.println(analogRead(adc));
    }
    if (input == 'G'){
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      Serial.print("LED OFF: ");
      Serial.println(analogRead(adc));
    }
    if (input == 'H'){
      int val = 0;
      int i = 0;
      while (i < 16){
        val += analogRead(adc);
        i += 1;
      }
      Serial.println(val);
    }
    
    //Serial.print(input);
  }
//  Serial.println("Hello World...");
//  delay(1000);  // do not print too fast!
}
