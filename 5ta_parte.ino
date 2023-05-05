#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
OneWire ourWire(2);                
DallasTemperature sensors(&ourWire);
#define led_verde 3
#define led_rojo 4
#define led_amarillo 5 
LiquidCrystal_I2C lcd_eduardo(0x27,16,2);

void setup(){
delay(1000);
lcd_eduardo.init();
lcd_eduardo.backlight();  
sensors.begin(); 
pinMode(led_verde, OUTPUT);
pinMode(led_rojo, OUTPUT);
pinMode(led_amarillo, OUTPUT); 
}

void loop() {
sensors.requestTemperatures();   
int temperatura1= sensors.getTempCByIndex(0); 
int temperatura2 = sensors.getTempFByIndex(0);
lcd_eduardo.setCursor(1,0);
lcd_eduardo.print("Temp1= ");
lcd_eduardo.print(temperatura1);
lcd_eduardo.print("C");
delay(100);  
lcd_eduardo.setCursor(0,1);
lcd_eduardo.print("Temp2=");
lcd_eduardo.print(temperatura2);
lcd_eduardo.print("F");
delay(100);

if(temperatura1 >=30){
digitalWrite(led_rojo, HIGH);
digitalWrite(led_verde, LOW);
digitalWrite(led_amarillo, LOW);
}
if(temperatura2 <=15){
digitalWrite(led_rojo, LOW);
digitalWrite(led_verde, HIGH);
digitalWrite(led_amarillo, LOW);
}
if(temperatura1 >=15 && temperatura1 <=30){
digitalWrite(led_rojo, LOW);
digitalWrite(led_verde, LOW);
digitalWrite(led_amarillo, HIGH);
}
}
