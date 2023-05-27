#ifndef DIBUJO_FIME_H
#define DIBUJO_FIME_H

#ifdef ARDUINO
  #if (ARDUINO >= 100)
    #include <Servo.h>
    #include <Arduino.h>
  #else
    #include <WProgram.h>
    #include <pins_arduino.h>
    #include <Servo.h>
  #endif
#endif

int map_grados_a_microsegundos(float grados);
void posicioninicial(Servo* m1, Servo* m2, Servo* m3);
void dibujoCirculo(Servo* m1, Servo* m2, Servo* m3);
void dibujoRectangulo(Servo* m1, Servo* m2, Servo* m3);
void dibujoCuadrado(Servo* m1, Servo* m2, Servo* m3);
void dibujoTriangulo(Servo* m1, Servo* m2, Servo* m3);
void bajarLapiz(Servo* m3);

#endif
