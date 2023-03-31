//definimos los botones 
#define push_alto10 10 //adelanto
#define push_bajo11 11  //retroseso       
int i=0;
struct Productos  
{
char nombre_producto[30];
float precio_unitario; 
int stock;
float precio_por_lote;
char reserva[20 ];
};
Productos producto1 = {"takis", 5.75, 25, 143.75, "Hay en bodega"};
Productos producto2 = {"chicle",1.25, 30, 37.5, "No hay en bodega"};
Productos producto3 = {"Pepsi",5.50, 28, 154, "Si hay en bodega"};
Productos producto4 = {"Galletas principe",4.12, 15, 61.8, "Si hay en bodega"};

Productos producto []= {producto1, producto2, producto3, producto4};

void setup() {
Serial.begin(9600);
Serial.print("Elija su comida ^^");
pinMode (push_alto10, INPUT);
pinMode (push_bajo11, INPUT);


}
void loop() {
{
  if(digitalRead(push_alto10)==HIGH)
  {
    delay (100);
    i++;
     if(i>3) i=0;
 Serial.println(i + 0);
 Serial.println("productos");
 Serial.println("Nombre del producto:");
 Serial.println(producto[i].nombre_producto);
 Serial.println(producto[i].precio_unitario);
 Serial.println(producto[i].stock);
 Serial.println(producto[i].precio_por_lote);
 Serial.println(producto[i].reserva);
  }

  if(digitalRead(push_bajo11)==HIGH)
  {
    delay(100);
    i--;
    if(i<0) i=3;
 Serial.println(i + 0);
 Serial.println("productos");
 Serial.println("Nombre del producto:");
 Serial.println(producto[i].nombre_producto);
 Serial.println(producto[i].precio_unitario);
 Serial.println(producto[i].stock);
 Serial.println(producto[i].precio_por_lote);
 Serial.println(producto[i].reserva);
  }

 delay(100);

}
}
