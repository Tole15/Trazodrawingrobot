#include <DibujoFIME.h>

#include <Servo.h>

// Pines de conexión para los servomotores
const int pin_m1 = 18;
const int pin_m2 = 19;
const int pin_m3 = 21;


Servo m1;
Servo m2;
Servo m3;
// Función para calibrar los servomotores
void calibrarServos() {
  m1.attach(pin_m1);
  m2.attach(pin_m2);
  m3.attach(pin_m3);

  // Calibrar el rango de movimiento
  m1.writeMicroseconds(map_grados_a_microsegundos(0));
  m2.writeMicroseconds(map_grados_a_microsegundos(0));
  m3.writeMicroseconds(map_grados_a_microsegundos(90));
  delay(5000);
  m1.writeMicroseconds(map_grados_a_microsegundos(180));
  m2.writeMicroseconds(map_grados_a_microsegundos(180));
  m3.writeMicroseconds(map_grados_a_microsegundos(180));
  delay(5000);

  // Centrar los servomotores
  m1.writeMicroseconds(map_grados_a_microsegundos(90));
  m2.writeMicroseconds(map_grados_a_microsegundos(90));
   m3.writeMicroseconds(map_grados_a_microsegundos(90));
  delay(5000);

  // Desconectar los servomotores
  m1.detach();
  m2.detach();
  m3.detach();
}

void setup() {
  // Inicializar los servomotores
  m1.attach(pin_m1);
    m2.attach(pin_m2);
    m3.attach(pin_m3);
 

  // Calibrar los servomotores
  calibrarServos();
}

void loop() {
  // Mover los servomotores a diferentes ángulos
  m1.writeMicroseconds(map_grados_a_microsegundos(180));
  m2.writeMicroseconds(map_grados_a_microsegundos(135));
  delay(1000);

  m1.writeMicroseconds(map_grados_a_microsegundos(90));
  m2.writeMicroseconds(map_grados_a_microsegundos(90));
  delay(1000);
}
