#include <SoftwareSerial.h>

SoftwareSerial sim(8, 4); // RX, TX
#define coi 5
#define cambien 2
String sdt = "0972115823";
long time;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
sim.begin(9600);
pinMode(cambien, INPUT_PULLUP);
pinMode(coi, OUTPUT);
Serial.println("DANG KHOI DONG");
delay(10000);
for(int i=0; i<=10;i++){
digitalWrite(coi, HIGH);
delay(100);
digitalWrite(coi, LOW);
delay(50);
Serial.println("DA KHOI DONG XONG");
}}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(cambien) == 0){
    digitalWrite(coi, HIGH);
    sim.println("ATD" + sdt +";");
    delay(20000);
    sim.println("ATH;");
    digitalWrite(coi, LOW);
    delay(1000);
}
else{
  digitalWrite(coi, LOW);
}
}
