int leds[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int i;
void setup() {
for (int  i = 0; i<10; i++){
  pinMode (leds[i],OUTPUT);
  } 
for (int i = 10; i>0; i--){
 } 
}


void loop() {
for (int i = 0; i<10; i++){
     digitalWrite(leds[i],HIGH);
     delay(500);
     digitalWrite(leds[i], LOW);
 }
for (int i = 10; i>0; i--){
  digitalWrite(leds[i], HIGH);
  delay(500);
  digitalWrite(leds[i], LOW);
  }
}
