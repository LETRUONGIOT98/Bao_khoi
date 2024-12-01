#define lua 3
#define mq A0
#define coi 2
#define led 13
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  Serial.begin(9600);
  pinMode(lua, INPUT_PULLUP);
  pinMode(mq, INPUT);
  pinMode(coi, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

void loop() {
  int val = analogRead(mq);
  int nongdo = map(val,0,1023,100,0);
  if(nongdo <= 0) nongdo = 0;
  if(nongdo >= 100) nongdo = 100;
  lcd.setCursor(0, 0);
  lcd.print("NONG DO:      %");
  lcd.setCursor(10, 0);
  lcd.print(nongdo);
  if(digitalRead(lua) == 0 || nongdo >= 10){
    digitalWrite(coi, HIGH);
    digitalWrite(led, HIGH);
    lcd.setCursor(0,1);
  lcd.print(" CANH BAO CHAY  ");
  }
  else{
    digitalWrite(coi, LOW);
    digitalWrite(led, LOW);
    lcd.setCursor(0,1);
  lcd.print("  BINH THUONG   ");
  }
  delay(100);
}
