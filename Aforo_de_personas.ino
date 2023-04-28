  #include <LiquidCrystal.h>
#define Trigger 9   
#define Echo    10
#define RS  6
#define enable  7
#define D4  2
#define D5  3
#define D6  4
#define D7  5
#define Buzzer 11

byte mano_lado[] = {
  B00000,
  B01110,
  B01110,
  B00100,
  B01110,
  B01110,
  B00100,
  B01010

};
byte mano_abajo[] = {
  B00000,
  B01110,
  B01110,
  B00100,
  B00100,
  B11111,
  B00100,
  B01010
};

int contador = 0;

LiquidCrystal LCD_eduardo(RS, enable, D4, D5, D6, D7); 
void setup()
{
  LCD_eduardo.begin(16,2); 
  LCD_eduardo.print("contador personas");
  
  LCD_eduardo.createChar(1,mano_lado);
  LCD_eduardo.createChar(2,mano_abajo);
  LCD_eduardo.setCursor(0,0);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo,INPUT);
}

void loop()
{
    long sensor, distancia; 
    delay(500);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(2);
    digitalWrite (Trigger, LOW);
    delayMicroseconds(5);
    sensor = pulseIn(Echo, HIGH);
    distancia = sensor/59;
  
    if(distancia >= 6 && distancia <= 10){
     contador++;
     switch(contador){
      case 1:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("1");
       break;
      case 2:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("2");
       break;
      case 3:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("3");
       break;
      case 4:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("4");
       break;
      case 5:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("5");
       break;
      case 6:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("6");
       break;
      case 7:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("7");
       break;
      case 8:
        LCD_eduardo.setCursor(0,0);
        LCD_eduardo.print("8");
       break;
      case 9:
       LCD_eduardo.setCursor(0,0);
       LCD_eduardo.print("9");
       break;
       case 10:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("10");
       break;
       case 11:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("11");
       break;
       case 12:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("12");
       break;
       case 13:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("13");
       break;
       case 14:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("14");
       break;
       case 15:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("15");
       break;
       case 16:
         LCD_eduardo.setCursor(0,0);
         LCD_eduardo.print("16");
       break;
     }
    }
    if(contador>=16){
      tone(Buzzer,100);
      delay(250+50);
      LCD_eduardo.clear();
      LCD_eduardo.setCursor(0,0);
      LCD_eduardo.write(1);
      delay(1000);
      LCD_eduardo.setCursor(0,0);
      LCD_eduardo.write(2);
      delay(1000);
    }
}
