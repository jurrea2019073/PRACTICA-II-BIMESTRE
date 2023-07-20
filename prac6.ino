#include <SparkFun_ADXL345.h>
#include <SPI.h>
#include <Wire.h>
#include <LedControl.h>

#define entrada 10      //pin 12 conectado al pin de datos del max7219.
#define clocks 9   //pin 11 conectado al pin de clock del max7219.
#define cs  8   //pin 10 conectado al pin de carga del max7219.

LedControl matriz = LedControl(entrada, clocks, cs, 1);
ADXL345 acelerometro = ADXL345();

byte circulo1[8] = {       // array que contiene todos los elementos de las
 0b11000011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11011011,
  0b11011011,
  0b11011011,
  0b11011011
};
byte circulo2[8] = {      // array que contiene todos los elementos de las
B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11011011,
  B11011011,
  B11000011,
  B11000011
};

byte circulo3[8] = {      // array que contiene todos los elementos de las
  0b11011011,
  0b11011011,
  0b11011011,
  0b11011011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011


};

unsigned long tiempo = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("iniciar");
  Serial.println();
  acelerometro.powerOn();
  acelerometro.setRangeSetting(8);
  matriz.shutdown(0, false); //Activo el max7219 para poder mostrar los digitos.
  matriz.setIntensity(0, 15); //Brilo a la mitad
  matriz.clearDisplay(0);
}

void loop() {
  messi();
}


void messi() {
  int x, y, z;
  acelerometro.readAccel(&x, &y, &z);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("; ");
  Serial.print("y:");
  Serial.print(y);
  Serial.println("");
Serial.print("Z:");
  Serial.print(z);
  Serial.print("; ");

  delay(80);
  if (x == 0 && y >= 3 && y <= 5) {
    for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, circulo1[i]);
    }
  }
  delay(tiempo);
  if (x >= -30 && y >= 3 && x <= -1 && y <= 14) {
    for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, circulo3[i]);
    }
  }
  delay(tiempo);
  if (x >= 2 && y >= -60 && x <= 030 && y <= 60) {
    for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, circulo2[i]);
    }
  }
  delay(tiempo);
}
