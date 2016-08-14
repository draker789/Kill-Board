
#include <SoftwareSerial.h>

int8_t incomingByte;
int8_t temp;
int hardware_kill;
SoftwareSerial mySerial(3, 2); // RX, TX

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
incomingByte = 1;
hardware_kill = 1;
temp = 1;
pinMode(7, INPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(7) == HIGH){
  hardware_kill = 1;
}
else if (digitalRead(7) == LOW){
  hardware_kill = 0; 
}
//Serial.print("hardkill status: ");
//Serial.print(hardware_kill);

  // read the incoming byte:
  if (mySerial.available() > 0){
    temp = mySerial.read();
//    Serial.print("   temp: ");
//    Serial.print(temp, BIN);
  }
  
if (temp == 1){
  incomingByte = 1;
}
if (temp == 2){
  incomingByte = 0;
}

//Serial.print("    softkill status: ");
//Serial.print(incomingByte, DEC); 
if ((hardware_kill == 1) && (incomingByte == 1)){
  // say what you got:
//  Serial.println("    Normal Operations");
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}
else{
//  Serial.println("    Kill Vehicle");
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  }
}

