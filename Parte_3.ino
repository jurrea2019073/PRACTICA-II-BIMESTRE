/* Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: ALARMA DE DISTANCIA 
   Jorge Eduardo Urrea Guerra 2019073
   Fecha: 4 de mayo
   */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8
#define led6 9
#define led7 10
#define led8 12
#define led9 13
#define led10 A1
#define Buzzer 11
#define trigger 2  
#define echo    3

LiquidCrystal_I2C lcd_eduardo(0x27,16,2);

void setup() {
  lcd_eduardo.init();
  lcd_eduardo.backlight();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(Buzzer, OUTPUT);
}
 
void loop() {
    int ditancia=dis();
    if(ditancia >=45){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(0,0);
      lcd_eduardo.print("Fuera de alcance");
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);      
    }
    else if(ditancia >=30 && ditancia <=40){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(0,0);
      lcd_eduardo.print("Persona/objeto");
      lcd_eduardo.setCursor(0,1);
      lcd_eduardo.print("Acercandose");
      lcd_eduardo.setCursor(0,1);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);
     
    }
     else if(ditancia >=15 && ditancia <=25){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(0,0);
      lcd_eduardo.print("Cuidado espacio");
      lcd_eduardo.setCursor(0,1);
      lcd_eduardo.print("Privado");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);
      tone(Buzzer, 100);
      delay(5000);
      noTone(Buzzer);
    }
    else if(ditancia >=5 && ditancia <=10){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(0,0);
      lcd_eduardo.print("Invadiendo");
      lcd_eduardo.setCursor(0,1);
      lcd_eduardo.print("Espacio Privado");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,HIGH);
      digitalWrite(led7,HIGH);
      digitalWrite(led8,HIGH);
      digitalWrite(led9,HIGH);
      digitalWrite(led10,HIGH);
      tone(Buzzer, 500);
      delay(10000);
      noTone(Buzzer);  
    }
}

int dis(){
   long sensor, distancia;
    delay(500);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(2);
    digitalWrite (trigger, LOW);
    delayMicroseconds(5);
    sensor = pulseIn(echo, HIGH);
    distancia = sensor/59;
    return distancia;
}
