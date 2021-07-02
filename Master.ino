#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 493

#define ACTIVATED LOW 

const int PIEZO = 11; 

const int BUTTON_C = 10;
const int BUTTON_D = 9;
const int BUTTON_E = 8;
const int BUTTON_F = 7;
const int BUTTON_G = 6;
const int BUTTON_A = 5;
const int BUTTON_B = 4;
const int BUTTON_START = 3;
const int BUTTON_WRONG = 2;
const int BUTTON_RIGHT = 13;

char song1[6] = {"CDAGF"};
char song2[6] = {"FGADC"};
char song3[6] = {"CDCDF"};

char currentSong[6];


char correct[6] = {"FGABF"};
char igrano[6];
int index = 0;
boolean pisi = true;
int potencioValue = 1;



void setup()
{
  pinMode(BUTTON_RIGHT, OUTPUT);
  pinMode(BUTTON_WRONG, OUTPUT);
  
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_D, INPUT);
  digitalWrite(BUTTON_D,HIGH);
  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E,HIGH);
  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_B, INPUT);
  digitalWrite(BUTTON_B,HIGH);
  pinMode(BUTTON_START, INPUT);
  digitalWrite(BUTTON_START,HIGH);
  
  digitalWrite(BUTTON_RIGHT,LOW);
  digitalWrite(BUTTON_WRONG,HIGH);
  strcpy(currentSong, song1);

  Serial.begin(9800);
}

void loop()
{
  if(index == 5){
    index = 0;
  }
  while(digitalRead(BUTTON_C) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'C';
      pisi = false;
      index++;
    }
    tone(PIEZO, C);
  }
  pisi = true;
  while(digitalRead(BUTTON_D) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'D';
      pisi = false;
      index++;
    }
    tone(PIEZO, D);
  }
  pisi = true;
  while(digitalRead(BUTTON_E) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'E';
      pisi = false;
      index++;
    }
    tone(PIEZO, E);
  }
  pisi = true;
  while(digitalRead(BUTTON_F) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'F';
      pisi = false;
      index++;
    }
    tone(PIEZO, F);
  }
  pisi = true;
  while(digitalRead(BUTTON_G) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'G';
      pisi = false;
      index++;
    }
    tone(PIEZO, G);
  }
  pisi = true;
  while(digitalRead(BUTTON_A) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'A';
      pisi = false;
      index++;
    }
    tone(PIEZO, A);
  }
  pisi = true;
  while(digitalRead(BUTTON_B) == ACTIVATED)
  {
    if(pisi){
      igrano[index] = 'B';
      pisi = false;
      index++;
    }
    tone(PIEZO, B);
  }
  pisi = true;
  noTone(PIEZO);
  Serial.print(currentSong);
  Serial.print(" ");
  Serial.println(igrano);
  if(isSame(currentSong, igrano)){
    digitalWrite(BUTTON_RIGHT,HIGH);
    digitalWrite(BUTTON_WRONG,LOW);
    delay(500);
    for(int j = 0; j < sizeof(igrano); j++){
        igrano[j] = 'A';
        play(correct[j]);
      }
  }
  else{
    digitalWrite(BUTTON_RIGHT,LOW);
    digitalWrite(BUTTON_WRONG,HIGH);
  }
  if(digitalRead(BUTTON_START) == ACTIVATED){
      while (Serial.available()) {
        potencioValue = Serial.read();
      }
      delay(100);
      while (Serial.available()) {
        potencioValue = Serial.read();
      }
      if(potencioValue == 1){
        strcpy(currentSong, song1);
      }
      else if(potencioValue == 2){
        strcpy(currentSong, song2);
      }
      else{
        strcpy(currentSong, song3);
      }
      index = 0;
      for(int j = 0; j < 5; j++){
        igrano[j] = 'A';
      }
      for(int i = 0; i < sizeof(currentSong); i++){
      play(currentSong[i]);
    }
  }
  
}
void play(char x){
  if(x == 'C'){
    tone(PIEZO, C);
  }
  else if(x == 'D'){
     tone(PIEZO, D);
  }
  else if(x == 'E'){
    tone(PIEZO, E);
  }
  else if(x == 'F'){
    tone(PIEZO, F);
  }
  else if(x == 'G'){
    tone(PIEZO, G);
  }
  else if(x == 'A'){
    tone(PIEZO, A);
  }
  else if(x == 'B'){
    tone(PIEZO, B);
  }
  delay(1000);
  noTone(PIEZO);
}
boolean isSame(char prva[], char druga[]){
  boolean vrni = true;
  for(int i = 0; i < 5; i++){
    if(prva[i] != druga[i]){
      vrni = false;
    }
  }
  return vrni;
}
