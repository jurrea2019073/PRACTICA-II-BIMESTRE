#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trigger 2   
#define echo    3
byte lleno[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

LiquidCrystal_I2C lcd_eduardo(0x27,16,2);
void setup() {
  lcd_eduardo.init();
  lcd_eduardo.backlight();
  pinMode(trigger, OUTPUT);
  pinMode(echo,INPUT);
  lcd_eduardo.createChar(1,lleno);

}

void loop() {
  int distancia=dis();
    if(distancia >=50){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(7,0);
      lcd_eduardo.print("50");  
       lcd_eduardo.setCursor(6,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(5,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(4,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(3,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(2,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(1,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(0,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(9,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(10,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(11,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(12,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(13,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(14,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(15,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(16,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(6,1); 
      lcd_eduardo.print("Libre");
    }
    if(distancia >=15 && distancia <=35){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(7,0);
      lcd_eduardo.print("30");
      lcd_eduardo.setCursor(6,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(5,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(4,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(3,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(2,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(9,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(10,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(11,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(12,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(13,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(5,1); 
      lcd_eduardo.print("Cuidado");
    }
     if(distancia >=10 && distancia <=15){
      lcd_eduardo.clear();
      lcd_eduardo.setCursor(7,0);
      lcd_eduardo.print("10");
     lcd_eduardo.setCursor(6,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(5,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(4,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(9,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(10,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(11,0); 
      lcd_eduardo.write(1);
      lcd_eduardo.setCursor(6,1); 
      lcd_eduardo.print("Alto");
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
