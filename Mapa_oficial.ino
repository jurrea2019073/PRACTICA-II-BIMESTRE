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
const int res_muni = 8;

String muni(res_muni);
String municipios[]= {"Peten", "Izabal", "Quiche", "Huehuetenango", "Escuintla", "San Marcos", "Jutiapa", "Baja Verapaz", "Santa Rosa", "Zacapa", "suchitepequez", "chiquimula", "Guatemala"};
String capitales[]= {"Flores", "Puerto Barrios", "Santa Cruz del Quiche", "Huehuetenango", "Escuintla", "San Marcos", "Jutiapa", "Salamá", "Cuilapa", "Zacapa", "Mazatenango", "Chiquimula","Guatemala"};

PCF8574 expansor_PCF1(0x27);
PCF8574 expansor_PCF2(0x26);
void setup() {
muni[0]= "Jalapa";
muni[1]= "chimaltenango";
muni[2]= "quetzaltenango",
muni[3]= "el progreso";
muni[4]= "retalhuleu";
muni[5]= "solola";
muni[6]= "totonicapan";
muni[7]= "Sacatepequez";

expansor_PCF1.begin();
expansor_PCF2.begin();
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
  if (respuesta,(capitales[indiceMunicipio])) {
    digitalWrite(pinesLED[indiceMunicipio], HIGH);
    Serial.println("Respuesta correcta");
    song1();
    } 
    else {
    Serial.println("Respuesta incorrecta");
    digitalWrite(pinesLED, LOW);
song2();
  }
 
if (indiceMunicipio == "jalapa" && respuesta == "jalapa"){
expansor_PCF1.write(expansor1_0,PCF8574_HIGH);
    Serial.println("Respuesta correcta"); 
   song1();
}
    else{
    expansor_PCF1.write(expansor1_0,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    song2();
    }
if (indiceMunicipio == "chimaltenango" && respuesta == "chimaltenango"){
expansor_PCF1.write(expansor1_1,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
}
    else{
    expansor_PCF1.write(expansor1_1,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    }  
if (indiceMunicipio == "quetzaltenango" && respuesta == "quetzaltenango"){
expansor_PCF1.write(expansor1_2,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
}
    else{
    expansor_PCF1.write(expansor1_2,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
      song2();
    } 
    if (indiceMunicipio == "El progreso" && respuesta == "Guastatoya"){
expansor_PCF1.write(expansor1_4,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
    }
    else{
    expansor_PCF1.write(expansor1_4,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
        song2();

    } 
    if (indiceMunicipio == "Retalhuleu" && respuesta == "Retalhuleu"){
expansor_PCF1.write(expansor1_5,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
}
    else{
        song2();
    expansor_PCF1.write(expansor1_5,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    } 
  if (indiceMunicipio == "Solola" && respuesta == "solola"){
expansor_PCF1.write(expansor1_6,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
}
    else{
        song2();
    expansor_PCF1.write(expansor1_6,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    } 
  if (indiceMunicipio == "totonicapan" && respuesta == "totonicapan"){
expansor_PCF1.write(expansor1_7,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
}
    else{
        song2();
    expansor_PCF1.write(expansor1_7,PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    } 

   
if (indiceMunicipio == "sacatepequez" &&  respuesta == "antigua Guatemala"){

expansor_PCF2.write(expansor2_0,PCF8574_HIGH);
    Serial.println("Respuesta correcta");
    song1();
     }
    else{
        song2();
    expansor_PCF1.write(expansor2_1, PCF8574_LOW);
    Serial.println("Respuesta incorrecta");
    } 

    delay(1000);
}
