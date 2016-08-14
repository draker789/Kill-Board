
#include <SoftwareSerial.h>
int8_t sentByte;

SoftwareSerial mySerial(7, 6); // RX, TX

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(2, INPUT);
pinMode(3, OUTPUT);
}

void loop() {
digitalWrite(3, HIGH);
  // put your main code here, to run repeatedly:
if (digitalRead(2)== HIGH){
  sentByte = 1;
}
else{
  sentByte = 2;
}
  mySerial.write(sentByte);
  Serial.print("Sending Kill Status: ");
  Serial.println(sentByte);
  delay(300);
}
