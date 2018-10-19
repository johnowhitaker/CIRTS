int l1 = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;
int l5 = 6;
int l6 = 7;
int l7 = 8;
int l8 = 9;

int d1 = A9;
int d2 = A8;
int d3 = A2;
int d4 = A3;
int d5 = A4;
int d6 = A5;
int d7 = A6;
int d8 = A7;

int led = 13;
int led2 = 20;


int DT = 10; //delay time when stepping - dictates max speed

int pos_a = 0;
int pos_b = 0;

int read(int a){
  int val = 0;
  int i = 0;
  while (i < 16){
    val += analogRead(a);
    i += 1;
  }
  return val/16;
}

void setup()
{
  Serial.begin(115200); // USB is always 12 Mbit/sec
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(d1, INPUT);
  pinMode(d2, INPUT);
  pinMode(d3, INPUT);
  pinMode(d4, INPUT);
  pinMode(d5, INPUT);
  pinMode(d6, INPUT);
  pinMode(d7, INPUT);
  pinMode(d8, INPUT);
}


void loop()
{

  if (Serial.available()){
    char input = Serial.read();
    if (input == 'a'){
      Serial.println("LED1 on");
      digitalWrite(l1, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'b'){
      Serial.println("LED2 on");
      digitalWrite(l2, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'c'){
      Serial.println("LED3 on");
      digitalWrite(l3, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'd'){
      Serial.println("LED4 on");
      digitalWrite(l4, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'e'){
      Serial.println("LED5 on");
      digitalWrite(l5, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'f'){
      Serial.println("LED6 on");
      digitalWrite(l6, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'g'){
      Serial.println("LED7 on");
      digitalWrite(l7, HIGH);
      digitalWrite(led, HIGH);
    }
    if (input == 'h'){
      Serial.println("LED8 on");
      digitalWrite(l8, HIGH);
      digitalWrite(led, HIGH);
    }


    
    if (input == 'A'){
      Serial.println("LEDs OFF");
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(l3, LOW);
      digitalWrite(l4, LOW);
      digitalWrite(l5, LOW);
      digitalWrite(l6, LOW);
      digitalWrite(l7, LOW);
      digitalWrite(l8, LOW);
      digitalWrite(led, LOW);
    }
    if (input == 'B'){
      Serial.println("LEDs ON");
      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(l3, HIGH);
      digitalWrite(l4, HIGH);
      digitalWrite(l5, HIGH);
      digitalWrite(l6, HIGH);
      digitalWrite(l7, HIGH);
      digitalWrite(l8, HIGH);
      digitalWrite(led, HIGH);
    }
    // duplicate
    
    if (input == 'i'){
//      Serial.print("d1: ");
      Serial.println(read(d1));
    }
    if (input == 'j'){
//      Serial.print("d2: ");
      Serial.println(read(d2));
    }
    if (input == 'k'){
//      Serial.print("d3: ");
      Serial.println(read(d3));
    }
    if (input == 'l'){
//      Serial.print("d4: ");
      Serial.println(read(d4));
    }
    if (input == 'm'){
//      Serial.print("d5: ");
      Serial.println(read(d5));
    }
    if (input == 'n'){
//      Serial.print("d6: ");
      Serial.println(read(d6));
    }
    if (input == 'o'){
//      Serial.print("d7: ");
      Serial.println(read(d7));
    }
    if (input == 'p'){
//      Serial.print("d8: ");
      Serial.println(read(d8));
    }
    
    //Serial.print(input);
  }
//  Serial.println("Hello World...");
//  delay(1000);  // do not print too fast!
}
