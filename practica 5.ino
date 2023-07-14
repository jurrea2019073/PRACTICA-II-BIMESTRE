/* 
 *Fundacion kinal
 *Centro Educativo Tecnico Laboral Kinal
 *Elecctronia
 *Grado: Quinto
 *Seccion: A
 *Curso: Taller de Electronica Digital y Reparacion de Computadoras I
 *Nombre: Jorge Eduardo Urrea Guerra
 *Carnet: 2019073
 *Practica 5
 */

#include <Ticker.h>
#include <LedControl.h>   

#define entrada   12   
#define clockss 11   
#define cs  10   
int adc, conver;

//Constructores
LedControl matriz = LedControl(entrada,clockss,cs,1);

void medicion(void);
Ticker accion_med(medicion,2000);

byte hielo[8]= {     
 B10001000,
  B11100000,
  B11110000,
  B11111100,
  B11111010,
  B11100000,
  B11100000,
  B10010000
};
byte fuego[8]= {     
B10111001,
  B01011011,
  B00111100,
  B11111111,
  B11111111,
  B00111100,
  B01011011,
  B10111001
};


unsigned long tiempo = 850;   

//Prototipos de funciones
int alerta(unsigned char number);

void setup()
{
  Serial.begin(9600); 
  accion_med.start();
  matriz.shutdown(0,false); 
  matriz.setIntensity(0,15);  
  matriz.clearDisplay(0);   
}


void loop() 
{

accion_med.update();  
}

int alerta(unsigned char number)
{
 switch (number)
  {
    
    case (0):
    {
      for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,fuego[i]);
      }
      break;
    }
    
  }
  
}



void medicion(void)
{
  adc = analogRead(A0);
  conver = map (adc,0,1024,0,100);
  Serial.println(adc);
  Serial.println("porcentaje:");
  Serial.println(conver);
  delay(5000);
  
 if(adc>195){
  for(int i =0; i<7;i++)
  {
   alerta(i);
    delay(tiempo);
  }
 }
  else{
     for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,hielo[i]);
      }
      delay(tiempo);
      matriz.clearDisplay(0);
      delay(tiempo);
      for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,hielo[i]);
      }
  }
}
