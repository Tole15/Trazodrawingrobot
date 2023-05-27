/* dibujoTriangulo()
Función que controla los servomotores para dibujar un triángulo.
Utiliza dos arreglos de ángulos para los servomotores y los convierte
a microsegundos utilizando la función map_grados_a_microsegundos.
Luego, mueve los servomotores a los ángulos correspondientes en
intervalos de tiempo regulares.
Argumentos de entrada:
- m1: Puntero al objeto de la clase Servo que controla el primer servomotor.
- m2: Puntero al objeto de la clase Servo que controla el segundo servomotor.
- m3: Puntero al objeto de la clase Servo que controla el tercer servomotor.

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
dibujoTriangulo(m1, m2, m3);


  // Puedes agregar más llamadas a funciones o configuraciones adicionales en el setup si es necesario
}

void loop() {
  // Puedes dejar la función loop vacía si no necesitas ejecutar código en bucle
}
