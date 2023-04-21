int BuzzerPin = 11;
int Trigger = 2;
int Echo  = 3;
long sensor;
int distancia;
int c=261; 
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;
int gH=783;
int gSH=830;
int aH=880;

void setup() {
 pinMode(BuzzerPin, OUTPUT);
 pinMode(Trigger, OUTPUT);
 pinMode(Echo, INPUT);
}

void loop() {
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2,LOW);
sensor = pulseIn(3, HIGH);
distancia = sensor/59;  
  
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite (2, LOW);
  sensor = pulseIn(3, HIGH);
 distancia = sensor/59;
 
if(distancia == 4 && distancia <6 ){
tone(BuzzerPin, a, 500);
 delay(500+50);
}
if(distancia == 7 && distancia <9){
tone(BuzzerPin, f, 350);
 delay(350+50);
}
if(distancia == 10 && distancia <12){
tone(BuzzerPin, cH, 150);
 delay(150+50);
}
if(distancia == 13 && distancia <15){
tone(BuzzerPin, eH, 500);
 delay(500+50);
}
if(distancia == 16 && distancia <18){
tone(BuzzerPin,fH, 350 );
 delay(350+50);
}
if(distancia == 19&& distancia <21){
tone(BuzzerPin,gS, 500 );
 delay(500+50);
}
if(distancia == 22 && distancia <24){
tone(BuzzerPin,aH, 500);
 delay(500+50);
}
if(distancia == 25 && distancia <27){
tone(BuzzerPin,gSH, 250 );
delay(250+50);
}
if(distancia == 28 && distancia <30){
tone(BuzzerPin,gH, 250);
delay(250+50);
}
if(distancia == 31 && distancia <33){
tone(BuzzerPin,fSH, 125 );
delay(125+50);
}
if(distancia == 34 && distancia <36){
tone(BuzzerPin,aS, 250);
delay(250+50);
}
if(distancia == 37 && distancia <39){
tone(BuzzerPin,dSH, 500);
delay(500+50);
}
if(distancia == 40 && distancia <42){
tone(BuzzerPin,dH, 250);
delay(250+50);
}
if(distancia == 43 && distancia <45){
tone(BuzzerPin,cSH, 250);
delay(250+50);
}
if(distancia == 46 && distancia <48){
tone(BuzzerPin,b, 125);
delay(125+50);
}
if(distancia == 49 && distancia <51){
tone(BuzzerPin,c, 125);
delay(125+50);
}
}
