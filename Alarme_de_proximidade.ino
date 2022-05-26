const int TRIG = 3;
const int ECHO = 2;
const int distancia1 = 80;
const int distancia2 = 50;
void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);
    if(distancia >= distancia2 and distancia <= distancia1){
      digitalWrite(11, 0);
      digitalWrite(12, 1);
      digitalWrite(13, 0);
      tone(10, 300);
      delay(500);
      tone(10, 400);
      delay(500);
    }
    else if(distancia <= distancia2) {
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 1);
      tone(10, 700);
      delay(500);
      tone(10, 800);
      delay(500);
    }
    else {
      noTone(10);
      digitalWrite(11, 1);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
    }
  delay(100);
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
