
#include <ST7032_asukiaaa.h>

ST7032_asukiaaa lcd;

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int stepPin = 32;
const int directionPin = 33;
const int enablePin = 25;
const int buttom1 = 5;
const int buttom2 = 18;
const int buttom3 = 19;
int flag=0;
int timeDelay = 1;
int j =0;

void setup() {
  lcd.begin(16, 2);
  lcd.setContrast(55);
  pinMode(stepPin,OUTPUT);
  pinMode(directionPin,OUTPUT);
  pinMode(enablePin,OUTPUT);
  pinMode(buttom1,INPUT_PULLUP);
  pinMode(buttom2,INPUT_PULLUP);
  pinMode(buttom3,INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  
if(digitalRead(buttom1)==0){
  digitalWrite(enablePin,1);
  digitalWrite(directionPin,1);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("protiv");

  for (int i = 0;i<2048*j;i++)
  {
    digitalWrite(stepPin,0);
    delay(timeDelay);
    digitalWrite(stepPin,1);
    delay(timeDelay);

  }
}

  if(digitalRead(buttom2)==0){
  digitalWrite(enablePin,1);
  digitalWrite(directionPin,0);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("pochas");
  for (int i = 0;i<2048*j;i++)
  {
    digitalWrite(stepPin,0);
    delay(timeDelay);
    digitalWrite(stepPin,1);
    delay(timeDelay);

  }
  }
  while(digitalRead(buttom3)==0){
    j++;
    
    Serial.print("j");
    lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(j);
  delay(1000);
  if(j==10){j=-1;}
  }
}
