const int BUTTON_EASY = 2;
const int BUTTON_MEDIUM = 3;
const int BUTTON_HARD = 4;
int sensorValue = 0;

void setup() {
  pinMode(BUTTON_EASY, OUTPUT);
  pinMode(BUTTON_MEDIUM, OUTPUT);
  pinMode(BUTTON_HARD, OUTPUT);
  Serial.begin(9800);
}

void loop() {
  sensorValue = analogRead(A0);
  if(sensorValue <= 341){
    digitalWrite(BUTTON_EASY,HIGH);
    digitalWrite(BUTTON_MEDIUM,LOW);
    digitalWrite(BUTTON_HARD,LOW);
    Serial.write(1);
  }
  else if(sensorValue <= 682){
    digitalWrite(BUTTON_EASY,LOW);
    digitalWrite(BUTTON_MEDIUM,HIGH);
    digitalWrite(BUTTON_HARD,LOW);
    Serial.write(2);
  }
  else{
    digitalWrite(BUTTON_EASY,LOW);
    digitalWrite(BUTTON_MEDIUM,LOW);
    digitalWrite(BUTTON_HARD,HIGH);
    Serial.write(3);
  }       
}
