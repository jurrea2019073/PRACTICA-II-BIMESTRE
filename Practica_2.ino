#define led 3
#define poten A0

int intensidad; 

void setup() {
digitalWrite(led, OUTPUT);

}

void loop() {
intensidad  = analogRead(poten) /4;
analogWrite(led, intensidad);
}
