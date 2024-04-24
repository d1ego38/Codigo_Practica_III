/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Cátalogo de productos
   Dev: Diego Emanuel Yos Pinzón
   Fecha: 19 de abril

*/

#define push_button_avance 2 // Avance
#define push_button_retroceso 3 // Retroceso
#define configINPUT(pin) pinMode(pin, INPUT) 
#define pausa delay(600)

struct datos_producto
{
  String nombre_producto;
  byte disponibilidad;
};

byte seleccion = 0;

datos_producto disponibilidad[4] = {
  {"Skittles", 25},
  {"Snickers", 30},
  {"M&M", 35},
  {"Polo", 25},
};

void setup() {
  Serial.begin(9600);
  configINPUT(push_button_avance); 
  configINPUT(push_button_retroceso); 
  Serial.println("Bienvenido :)");
  Serial.println("Productos:");
}  
  
void loop() {
  if (digitalRead(push_button_avance) == HIGH) {
    if (seleccion == 3) {
      seleccion = 0;
    } else {
      seleccion = seleccion + 1;
    }
    Serial.println("Producto: " + disponibilidad[seleccion].nombre_producto);
    Serial.println("La cantidad en stock: " + String(disponibilidad[seleccion].disponibilidad)); 
    pausa;
  }
 
  if (digitalRead(push_button_retroceso) == HIGH) {
    if (seleccion == 0) {
      seleccion = 3;
    } else {
      seleccion = seleccion - 1;
    }
    Serial.println("Producto: " + disponibilidad[seleccion].nombre_producto);
    Serial.println("La cantidad en stock: " + String(disponibilidad[seleccion].disponibilidad)); 
    pausa;
  }
}
