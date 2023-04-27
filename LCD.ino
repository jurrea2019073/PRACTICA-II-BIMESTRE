#include <LiquidCrystal.h>
#define RS 6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
LiquidCrystal LCD_eduardo(RS,Enable,D4,D5,D6,D7);
void setup() {
LCD_eduardo.begin(16,2);
}
void loop() {
LCD_eduardo.setCursor(0,0);
LCD_eduardo.print("Jorge Urrea");
LCD_eduardo.setCursor(0,1);
LCD_eduardo.print("2019073");

}
