#define led_rojo 3
#define led_verde 5 
#define led_azul 6
#define poten A0
int tiempo;
void setup() {
pinMode(led_rojo, OUTPUT);
pinMode(led_azul, OUTPUT);
pinMode(led_verde, OUTPUT);
}

void loop() {
tiempo = map(analogRead(poten), 0, 1023, 100,1000);
analogWrite(led_rojo, 174);
analogWrite(led_verde, 92);
analogWrite(led_azul, 230);
delay(tiempo);

analogWrite(led_rojo, 255);
analogWrite(led_verde, 255);
analogWrite(led_azul, 255);
delay(tiempo);

analogWrite(led_rojo, 255);
analogWrite(led_verde, 255);
analogWrite(led_azul, 255);
delay(tiempo);

analogWrite(led_rojo, 0);
analogWrite(led_verde, 255);
analogWrite(led_azul, 255);
delay(tiempo);

analogWrite(led_rojo, 189);
analogWrite(led_verde, 174);
analogWrite(led_azul, 20);
delay(tiempo);

analogWrite(led_rojo, 255);
analogWrite(led_verde, 87);
analogWrite(led_azul, 35);
delay(tiempo);
}
