/*  posicioninicial()
    Función que mueve los servomotores a una posición inicial.
    Utiliza valores predefinidos de grados y los convierte a microsegundos
    utilizando la función map_grados_a_microsegundos. Luego, establece
    los microsegundos correspondientes en los servomotores.
    
    Argumentos de entrada:
    - Ninguno.
    
    Retorna:
    - Nada.
*/


#include "DibujoFIME.h"
#include <Servo.h>
Servo *m1 = new Servo();
Servo *m2 = new Servo();
Servo *m3 = new Servo();

void setup() {

m1->attach(18);
m2->attach(19);
m3->attach(21);

posicioninicial(m1, m2, m3);



  // Puedes agregar más llamadas a funciones o configuraciones adicionales en el setup si es necesario
}

void loop() {
  // Puedes dejar la función loop vacía si no necesitas ejecutar código en bucle
}
