#include <SoftwareSerial.h>
#include <Wire.h>
#include <PCF8574.h>
#define PCF8574_HIGH LOW 
#define PCF8574_LOW HIGH

PCF8574 expansor_PCF1(0x20);

String recepcion;
#define led1 2
#define led2 3
#define led3 4
#define led4 5 
#define led5 6
#define led6 7
#define led7 8
#define led8 25
#define led9 288
#define led10 12
#define led11 13
#define led12 A0
#define led13 A1
#define led14 A2
#define led15 A3

int buzzerPin= 9;

SoftwareSerial blue (10,11);
void setup() {
  pinMode(buzzerPin, OUTPUT);

pinMode(led1,OUTPUT);  
pinMode(led2, OUTPUT);   
pinMode(led3, OUTPUT);   
pinMode(led4, OUTPUT);  
pinMode(led5, OUTPUT);   
pinMode(led6, OUTPUT);   
pinMode(led7, OUTPUT);  
pinMode(led8, OUTPUT);   
pinMode(led9, OUTPUT);  
pinMode(led10, OUTPUT);   
pinMode(led11, OUTPUT);   
pinMode(led12, OUTPUT);   
pinMode(led13, OUTPUT);   
pinMode(led14, OUTPUT);   
pinMode(led15, OUTPUT);   


}
void song1(){
  
  tone(buzzerPin, 262);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 262);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 330);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 392);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 523);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 392);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 208);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 262);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 311);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 415);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 311);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 415);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 523);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 831);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 294);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 349);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 349);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 587);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 587);
  delay(38);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 932);
  delay(37);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(38);
  noTone(buzzerPin);
}
void song2(){
  
  tone(buzzerPin, 65);
  delay(136);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(136);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(136);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(136);
  noTone(buzzerPin);

  tone(buzzerPin, 262);
  delay(136);
  noTone(buzzerPin);
} 
void loop() {

if (blue.available()){
  recepcion=blue.read(); 
if(recepcion ==String("1")){
  digitalWrite(led1, HIGH);
  song1();
}
if(recepcion ==String("1f")){
digitalWrite(led1, LOW);
song2();
}

if(recepcion ==String("2")){
  digitalWrite(led2, HIGH);
  song1();
}
if(recepcion ==String("2f")){
digitalWrite(led2, LOW);
song2();
}
if(recepcion ==String("3")){
  digitalWrite(led3, HIGH);
  song1();
}
if(recepcion==String("3f")){
digitalWrite(led3, LOW);
song2();
}

if(recepcion ==String("4")){
  digitalWrite(led4, HIGH);
  song1();
}
if(recepcion ==String("4f")){
digitalWrite(led4, LOW);
song2();
}

if(recepcion ==String("5")){
  digitalWrite(led5, HIGH);
  song1();
}
if(recepcion ==String("5f")){
digitalWrite(led5, LOW);
song2();
}

if(recepcion ==String("6")){
  digitalWrite(led6, HIGH);
  song1();
}
if(recepcion ==String("6f")){
digitalWrite(led6, LOW);
song2();
}

if(recepcion ==String("7")){
  digitalWrite(led7, HIGH);
  song1();
}
if(recepcion ==String("7f")){
digitalWrite(led7, LOW);
song2();
}

if(recepcion ==String("8")){
  digitalWrite(led8, HIGH);
  song1();
}
if(recepcion ==String("8f")){
digitalWrite(led8, LOW);
song2();
}
if(recepcion ==String("9")){
  digitalWrite(led9, HIGH);
  song1();
}
if(recepcion ==String("9f")){
digitalWrite(led9, LOW);
song2();
}
if(recepcion ==String("10")){
  digitalWrite(led10, HIGH);
  song1();
}
if(recepcion ==String("10f")){
digitalWrite(led10, LOW);
song2();
}
if(recepcion ==String("11")){
  digitalWrite(led11, HIGH);
  song1();
}
if(recepcion ==String("11f")){
digitalWrite(led11, LOW);
song2();
}
if(recepcion ==String("12")){
  digitalWrite(led12, HIGH);
  song1();
}
if(recepcion ==String("12f")){
digitalWrite(led12, LOW);
song2();
}
if(recepcion ==String("13")){
  digitalWrite(led13, HIGH);
  song1();
}
if(recepcion ==String("13f")){
digitalWrite(led13, LOW);
song2();
}
if(recepcion ==String("14")){
  digitalWrite(led14, HIGH);
  song1();
}
if(recepcion ==String("14f")){
digitalWrite(led14, LOW);
song2();
}
if(recepcion ==String("15")){
  digitalWrite(led15, HIGH);
  song1();
}
if(recepcion ==String("15f")){
digitalWrite(led15, LOW);
song2();
}
if(recepcion ==String("16")){
expansor_PCF1.write(0,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("16f")){
expansor_PCF1.write(0,PCF8574_LOW);
song2();
}
if(recepcion ==String("17")){
expansor_PCF1.write(1,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("18f")){
expansor_PCF1.write(1,PCF8574_LOW);
song2();
}
if(recepcion ==String("19")){
expansor_PCF1.write(2,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("19f")){
expansor_PCF1.write(2,PCF8574_LOW);
song2();
}
if(recepcion ==String("20")){
expansor_PCF1.write(4,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("20f")){
expansor_PCF1.write(4,PCF8574_LOW);
song2();
}
if(recepcion ==String("21")){
expansor_PCF1.write(5,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("21f")){
expansor_PCF1.write(5,PCF8574_LOW);
song2();
}
if(recepcion ==String("22")){
expansor_PCF1.write(7,PCF8574_HIGH);
  song1();
}
if(recepcion ==String("22f")){
expansor_PCF1.write(7,PCF8574_LOW);
song2();
}
}
}
