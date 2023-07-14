/* 
 *Fundacion kinal
 *Centro Educativo Tecnico Laboral Kinal
 *Elecctronia
 *Grado: Quinto
 *Seccion: A
 *Curso: Taller de Electronica Digital y Reparacion de Computadoras I
 *Nombre: Jorge Eduardo Urrea Guerra
 *Nombre: Diego Rodolfo Revolorio Lico
 *Carnet: 2019073
 *Proyecto: Practica 4
 */
#include <Wire.h>
#include <PCF8574.h>

int buzzerPin= 9;
int pinesLED[] = {2, 3, 4, 5, 6, 7, 8, 10,11,12,A0,A1,A2,A3,};
int cantidadLEDs = 21;

#define PCF8574_HIGH LOW 
#define PCF8574_LOW HIGH

#define expansor1_0 0
#define expansor1_1 1 
#define expansor1_2 2
#define expansor1_4 4
#define expansor1_5 5
#define expansor1_6 6 
#define expansor1_7 7

#define expansor2_0 0
#define expansor2_1 1
#define expansor2_2 2
#define expansor2_4 4
#define expansor2_5 5
#define expansor2_6 6
#define expansor2_7 7
String municipios[]= {"Peten", "Izabal", "Quiche", "Huehuetenango", "Escuintla", "San Marcos", "Jutiapa", "Baja Verapaz", "Santa Rosa", "Zacapa", "suchitepequez", "chiquimula", "Guatemala"};
String capitales[]= {"Flores", "Puerto Barrios", "Santa Cruz del Quiche", "Huehuetenango", "Escuintla", "San Marcos", "Jutiapa", "Salamá", "Cuilapa", "Zacapa", "Mazatenango", "Chiquimula","Guatemala"};

PCF8574 expansor_PCF1(0x27);
PCF8574 expansor_PCF2(0x26);
void setup() {

pinMode(buzzerPin, OUTPUT);
randomSeed(analogRead(A0));
  for (int i = 0; i < cantidadLEDs; i++) {
    pinMode(pinesLED[i], OUTPUT);
  }
  Serial.begin(9600);
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
  int indiceMunicipio = random(0, cantidadLEDs);

  String respuesta;
  Serial.print("¿Cuál es la capital de ");
  Serial.print(municipios[indiceMunicipio]);
  Serial.println("?");

  while (!Serial.available()) {
  }
  respuesta = Serial.readString();

  respuesta.trim(); 
  if (respuesta.equalsIgnoreCase(capitales[indiceMunicipio])){
    digitalWrite(pinesLED[indiceMunicipio], HIGH);
    Serial.println("Respuesta correcta");
    song1();
    } 
    else {
    Serial.println("Respuesta incorrecta");
    digitalWrite(pinesLED, LOW);
song2();
  }
}
