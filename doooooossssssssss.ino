/* 
 *Fundacion kinal
 *Centro Educativo Tecnico Laboral Kinal
 *Elecctronia
 *Grado: Quinto
 *Seccion: A
 *Curso: Taller de Electronica Digital y Reparacion de Computadoras I
 *Nombre: Jorge Eduardo Urrea Guerra
 *Carnet: 2019073
 *Proyecto: Practica 1
 */
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h> 
#define push_buton 4
OneWire ourWire(2);
DallasTemperature Sensors(&ourWire);


void isr_pushbutons();
void isr_temp();


volatile static bool estado_buton;
volatile static bool estado_temperatura;


Ticker isr_accion_buton(isr_pushbutons, 6000); //cada tres segundos se encendera/apagara el led del pin 13;
Ticker isr_accion_tempe(isr_temp, 3000); //cada tres segundos se encendera/apagara el led del pin 13;

void setup() {
 Serial.begin(19200);
 pinMode(push_buton, INPUT_PULLUP); 
 digitalWrite(push_buton, HIGH);
 Sensors.begin();
 isr_accion_buton.start();
 isr_accion_tempe.start();
estado_buton = HIGH;
}

void loop() {
isr_accion_buton.update();
isr_accion_tempe.update();
}

void isr_temp(void)
{
  Sensors.requestTemperatures();
  float temperatura= Sensors.getTempCByIndex(0); 
  Serial.println(temperatura);
}
void isr_pushbutons(void)
{
estado_buton = digitalRead(push_buton);
if(estado_buton == LOW){
 Serial.println("Se ha presionado el boton");
}
else
{
 Serial.println("No se ha presionado el boton");

}
}
