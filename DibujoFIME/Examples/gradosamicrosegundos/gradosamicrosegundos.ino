/*  map_grados_a_microsegundos()
    Función que mapea un valor de grados a un rango de microsegundos.
    Limita el rango de grados entre 0 y 180, y utiliza constantes
    predefinidas para los rangos de microsegundos mínimo y máximo.
    Luego, realiza una interpolación lineal para calcular el valor
    de microsegundos correspondiente al valor de grados.
    
    Argumentos de entrada:
    - grados: Valor de grados a mapear a microsegundos (float).
    
    Retorna:
    - Valor de microsegundos correspondiente al valor de grados (int).
*/

#include "DibujoFIME.h"
#include <Servo.h>
Servo *m1 = new Servo();
Servo *m2 = new Servo();
Servo *m3 = new Servo();
void setup() {
Serial.begin(9600);
m1->attach(18);
m2->attach(19);
m3->attach(21);

  float grados = 90.0;
  int microsegundos = map_grados_a_microsegundos(grados);
  Serial.println("");
Serial.println("los grados: "); Serial.print(grados); Serial.print(" son: "); Serial.print(microsegundos);
}

void loop() {
  // Aquí puedes agregar otras tareas o dejar el loop vacío si no necesitas que nada se repita.
} 
