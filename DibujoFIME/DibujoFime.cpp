//Este es el .cpp

#include "DibujoFIME.h"

/*_______________________________________________________________________________________________________________________________________________________*/



/* map_grados_a_microsegundos()

Descripción:
Esta función mapea un valor de grados a un rango de microsegundos.
Limita el rango de grados entre 0 y 180, y utiliza constantes
predefinidas para los rangos de microsegundos mínimo y máximo.
Luego, realiza una interpolación lineal para calcular el valor
de microsegundos correspondiente al valor de grados.

Prototipo:
int map_grados_a_microsegundos(float grados);

Argumentos de entrada:
grados Valor de grados a mapear a microsegundos (float).

Retorna:
Valor de microsegundos correspondiente al valor de grados (int).
*/



int map_grados_a_microsegundos(float grados) {
  // Limitar el rango de grados entre 0 y 180
  if (grados < 0) grados = 0;
  if (grados > 180) grados = 180;

  // Constantes para los rangos de microsegundos
  const int min_microsegundos = 544;
  const int max_microsegundos = 2400;

  // Mapear grados a microsegundos
  float porcentaje = grados / 180.0;
  int microsegundos = min_microsegundos + (max_microsegundos - min_microsegundos) * porcentaje;

  return microsegundos;
}

/*_________________________________________________________________________________________________________________________________________________________________________________________________*/


/* posicioninicial()

Descripción:
Esta función mueve los servomotores a una posición inicial.
Utiliza valores predefinidos de grados y los convierte a microsegundos
utilizando la función map_grados_a_microsegundos. Luego, establece
los microsegundos correspondientes en los servomotores.

Prototipo:
void posicioninicial();

Argumentos de entrada:
Ninguno.

Retorna:
Nada.
*/


 //OJO TODAS LAS FIGURAS DEBEN DE EMPEZAR EN LOS ANGULOS DE LA POSICION INICIAL.

void posicioninicial(Servo* m1, Servo* m2, Servo* m3) {
  m3->write(180);
  
  int microsegundos = map_grados_a_microsegundos(105.2418912576);
  m1->writeMicroseconds(microsegundos);
  microsegundos = map_grados_a_microsegundos(72.2102248837);
  m2->writeMicroseconds(microsegundos);
}



/*___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
/* dibujoCirculo()

Descripción:
Esta función controla los servomotores para dibujar un círculo.
Utiliza dos arreglos de ángulos para los servomotores y los convierte
a microsegundos utilizando la función map_grados_a_microsegundos.
Luego, mueve los servomotores a los ángulos correspondientes en
intervalos de tiempo regulares.

Prototipo:
void dibujoCirculo(Servo *m1, Servo *m2, Servo *m3);

Argumentos de entrada:
m1 Puntero al objeto de la clase Servo que controla el primer servomotor.
m2 Puntero al objeto de la clase Servo que controla el segundo servomotor.
m3 Puntero al objeto de la clase Servo que controla el tercer servomotor.

Retorna:
Nada.
*/
void dibujoCirculo(Servo *m1, Servo *m2, Servo *m3) {
float theta1[] = {105.16, 103.57, 101.81, 100.07, 98.98, 98.14, 97.69, 97.67, 98.23, 98.81, 98.98, 99.65, 100.45, 101.78, 101.71, 103.3, 104.51, 106.09, 108.79, 111.15, 113.46, 115.41, 116.15, 117.41, 119.37, 121.09, 122.26, 123.96, 125.58, 126.68, 127.56, 128.28, 128.08, 126.66, 124.4, 122.25, 120.06, 117.58, 114.83, 112.98, 111.05, 107.88, 105.16};
float theta4[] = {72.29, 70.63, 68.32, 65.38, 62.92, 60.14, 57.24, 57.08, 52.02, 50.77, 50.5, 49.74, 49.18, 48.81, 48.8, 48.88, 49.25, 49.97, 51.73, 53.6, 55.65, 57.49, 58.2, 59.45, 61.47, 63.29, 64.59, 66.58, 68.68, 70.32, 71.91, 73.86, 76.77, 78.32, 79.23, 79.52, 79.46, 79.1, 78.35, 77.61, 76.66, 74.61, 72.29};
int size_theta1 = sizeof(theta1) / sizeof(theta1[0]);
int size_theta4 = sizeof(theta4) / sizeof(theta4[0]);
    for (int i = 0; i <size_theta4; i++) {
        float grados1 = theta1[i];
        float grados2 = theta4[i];
        int microsegundos1 = map_grados_a_microsegundos(grados1);
        int microsegundos2 = map_grados_a_microsegundos(grados2);
        m1->writeMicroseconds(microsegundos1);
        m2->writeMicroseconds(microsegundos2);
        delay(100);
    }
}

/*______________________________________________________________________________________________________________________________________________________________________________________________________________________*/

/* dibujoRectangulo()

Descripción:
Esta función controla los servomotores para dibujar un rectángulo.
Utiliza dos arreglos de ángulos para los servomotores y los convierte
a microsegundos utilizando la función map_grados_a_microsegundos.
Luego, mueve los servomotores a los ángulos correspondientes en
intervalos de tiempo regulares.

Prototipo:
void dibujoRectangulo(Servo *m1, Servo *m2, Servo *m3);

Argumentos de entrada:
m1 Puntero al objeto de la clase Servo que controla el primer servomotor.
m2 Puntero al objeto de la clase Servo que controla el segundo servomotor.
m3 Puntero al objeto de la clase Servo que controla el tercer servomotor.

Retorna:
Nada.
*/


void dibujoRectangulo(Servo *m1, Servo *m2, Servo *m3) {
 

  float primeralinea[11][2] = {
    {105.241891257648, 72.2102248837234},
    {102.63150746229, 69.7231608726296},
    {99.9554543729, 67.2964541353},
    {97.2087013676, 64.9306524877},
    {94.3838255638653, 62.6271494118987},
    {91.4702209227, 60.388047657},
    {88.4528650808, 58.2160422797},
    {85.310292749, 56.1143177068},
    {82.0110437562, 54.0864558018},
    {78.506896449, 52.1363536383},
    {74.7184126446, 50.2681509358}
  };

  for (int j = 0; j < 11; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(primeralinea[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(primeralinea[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(30);
  }

delay(1500);

float segundalinea[11][2] = {
    {74.7184126446, 50.2681509358},
    {77.4284570865, 47.8086868456},
    {79.5705433724, 45.4575211757},
    {81.3146986993, 43.1963382404},
    {82.7511023768, 41.0107104924},
    {83.9333903256, 38.8889381233},
    {84.8956865818, 36.8212763161},
    {85.66055912, 34.7993967395},
    {86.2431957746, 32.815994782},
    {86.6537936036, 30.8644883778},
    {86.8990235448, 28.9387730691}
};


for (int j = 0; j < 11; j++) {
  int microsegundos_m1 = map_grados_a_microsegundos(segundalinea[j][0]);
  m1->writeMicroseconds(microsegundos_m1);
  
  int microsegundos_m2 = map_grados_a_microsegundos(segundalinea[j][1]);
  m2->writeMicroseconds(microsegundos_m2);
  
  delay(30);
}

delay(1500);

float terceralinea[21][2] = {
    {86.8990235448, 28.9387730691},
    {89.9205850059, 31.7568638593},
    {92.9334303674, 34.6635835213},
    {95.9453108412, 37.6445114849},
    {98.9626349123, 40.685250759},
    {101.9905919393, 43.7718485649},
    {105.0332043262, 46.8911787762},
    {108.0933255582, 50.0312635054},
    {111.1725971062, 53.1815195451},
    {114.2713754093, 56.3329244425},
    {117.3886399888, 59.4781053111},
    {120.5218946889, 62.6113600112},
    {123.6670755575, 65.7286245907},
    {126.8184804549, 68.8274028938},
    {129.9687364946, 71.9066744418},
    {133.1088212238, 74.9667956738},
    {136.2281514351, 78.0094080607},
    {139.314749241, 81.0373650877},
    {142.3554885151, 84.0546891588},
    {145.3364164787, 87.0665696326},
    {148.2431361407, 90.0794149941}
};

for (int j = 0; j < 21; j++) {
  int microsegundos_m1 = map_grados_a_microsegundos(terceralinea[j][0]);
  m1->writeMicroseconds(microsegundos_m1);
  
  int microsegundos_m2 = map_grados_a_microsegundos(terceralinea[j][1]);
  m2->writeMicroseconds(microsegundos_m2);
  
  delay(30);
}

delay(1500);

float cuartalinea[11][2] = {
    {148.2431361407, 90.0794149941},
    {146.4522617318, 90.3184076453},
    {144.6234598481, 90.7194625312},
    {142.7522191042, 91.2873266278},
    {140.8332892839, 92.0297601579},
    {138.8604895851, 92.958658965},
    {136.8264488927, 94.091828098},
    {134.7222460248, 95.4559607329},
    {132.536898363, 97.0920232771},
    {130.2566125764, 99.0659678268},
    {127.8636463617, 101.493103551}
};
for (int j = 0; j < 11; j++) {
  int microsegundos_m1 = map_grados_a_microsegundos(cuartalinea[j][0]);
  m1->writeMicroseconds(microsegundos_m1);
  
  int microsegundos_m2 = map_grados_a_microsegundos(cuartalinea[j][1]);
  m2->writeMicroseconds(microsegundos_m2);
  
  delay(100);
}


delay(1500);

float quintalinea[11][2] = {
    {127.8636463617, 101.493103551},
    {125.9135441982, 97.9889562438},
    {123.8856822932, 94.689707251},
    {121.7839577203, 91.5471349192},
    {119.611952343, 88.5297790773},
    {117.3728505881, 85.6161744361},
    {115.0693475123, 82.7912986324},
    {112.7035458647, 80.0445456271},
    {110.2768391274, 77.3684925377},
    {107.7897751163, 74.7581087424},
    {105.2418912576, 72.2102248837}
};
for (int j = 0; j < 11; j++) {
  int microsegundos_m1 = map_grados_a_microsegundos(quintalinea[j][0]);
  m1->writeMicroseconds(microsegundos_m1);
  
  int microsegundos_m2 = map_grados_a_microsegundos(quintalinea[j][1]);
  m2->writeMicroseconds(microsegundos_m2);
  
  delay(30); 
}

  }

/*_________________________________________________________________________________________________________________________________________________________________________________________________*/


/* dibujoCuadrado()

Descripción:
Esta función controla los servomotores para dibujar un cuadrado.
Utiliza dos arreglos de ángulos para los servomotores y los convierte
a microsegundos utilizando la función map_grados_a_microsegundos.
Luego, mueve los servomotores a los ángulos correspondientes en
intervalos de tiempo regulares.

Prototipo:
void dibujoCuadrado(Servo *m1, Servo *m2, Servo *m3);

Argumentos de entrada:
m1 Puntero al objeto de la clase Servo que controla el primer servomotor.
m2 Puntero al objeto de la clase Servo que controla el segundo servomotor.
m3 Puntero al objeto de la clase Servo que controla el tercer servomotor.

Retorna:
Nada.
*/


void dibujoCuadrado(Servo *m1, Servo *m2, Servo *m3) {


  float primeralineac[10][2] = {
      {105.2418912576, 72.2102248837},
      {107.145710908, 70.2823254806},
      {108.8630607226, 68.5306844364},
      {110.4155650653, 66.9353619429},
      {111.8178463635, 65.4827846135},
      {113.0795546181, 64.1639680979},
      {114.2065839447, 62.9734448692},
      {115.201817608, 61.9086093543},
      {116.0655810977, 60.9693273241},
      {116.7959028236, 60.157724432}
  };

  for (int j = 0; j < 10; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(primeralineac[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(primeralineac[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(30);
  }

  delay(500);

  float segundalineac[11][2] = {
      {117.3886399888, 59.4781053111},
      {120.5218946889, 62.6113600112},
      {123.6670755575, 65.7286245907},
      {126.8184804549, 68.8274028938},
      {129.9687364946, 71.9066744418},
      {133.1088212238, 74.9667956738},
      {136.2281514351, 78.0094080607},
      {139.314749241, 81.0373650877},
      {142.3554885151, 84.0546891588},
      {145.3364164787, 87.0665696326},
      {148.2431361407, 90.0794149941}
  };

  for (int j = 0; j < 11; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(segundalineac[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(segundalineac[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(30);
  }

  delay(500);

  float terceralineac[11][2] = {
      {148.2431361407, 90.0794149941},
      {146.4522617318, 90.3184076453},
      {144.6234598481, 90.7194625312},
      {142.7522191042, 91.2873266278},
      {140.8332892839, 92.0297601579},
      {138.8604895851, 92.958658965},
      {136.8264488927, 94.091828098},
      {134.7222460248, 95.4559607329},
      {132.536898363, 97.0920232771},
      {130.2566125764, 99.0659678268},
      {127.8636463617, 101.493103551}
  };

  for (int j = 0; j < 11; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(terceralineac[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(terceralineac[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(30);
  }

  delay(500);

  float cuartalineac[11][2] = {
      {127.8636463617, 101.493103551},
      {125.9135441982, 97.9889562438},
      {123.8856822932, 94.689707251},
      {121.7839577203, 91.5471349192},
      {119.611952343, 88.5297790773},
      {117.3728505881, 85.6161744361},
      {115.0693475123, 82.7912986324},
      {112.7035458647, 80.0445456271},
      {110.2768391274, 77.3684925377},
      {107.7897751163, 74.7581087424},
      {105.2418912576, 72.2102248837}
  };

  for (int j = 0; j < 11; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(cuartalineac[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(cuartalineac[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(30);
  }
}
/*_________________________________________________________________________________________________________________________________________________________________________________________________*/


/* dibujoTriangulo()

Descripción:
Esta función controla los servomotores para dibujar un triángulo.
Utiliza dos arreglos de ángulos para los servomotores y los convierte
a microsegundos utilizando la función map_grados_a_microsegundos.
Luego, mueve los servomotores a los ángulos correspondientes en
intervalos de tiempo regulares.

Prototipo:
void dibujoTriangulo(Servo *m1, Servo *m2, Servo *m3);

Argumentos de entrada:
m1 Puntero al objeto de la clase Servo que controla el primer servomotor.
m2 Puntero al objeto de la clase Servo que controla el segundo servomotor.
m3 Puntero al objeto de la clase Servo que controla el tercer servomotor.

Retorna:
Nada.
*/



void dibujoTriangulo(Servo *m1, Servo *m2, Servo *m3) {

 
  float primeralineat[21][2] = {
    {105.2418912576, 72.2102248837},
    {107.623196689, 72.5119242008},
    {109.9479055597, 72.8963656212},
    {112.3198240295, 73.3813175786},
    {114.4762280111, 73.903542657},
    {116.6979181056, 74.5218304115},
    {118.9001914752, 75.2135707911},
    {121.987210204, 76.3109296251},
    {123.2318305063, 76.7938896756},
    {124.4761083472, 77.2990467729},
    {125.4586336177, 77.7132450424},
    {127.6463303187, 78.6819952827},
    {129.8419503522, 79.7150848087},
    {132.0516881882, 80.811464367},
    {134.2790827553, 81.9688644038},
    {136.5275263946, 83.184861308},
    {138.8028821948, 84.4583652312},
    {141.1074885174, 85.7863320691},
    {143.4470825037, 87.1676355756},
    {145.8237735498, 88.5990417246},
    {148.2431361407, 90.0794149941}
  };

  for (int j = 0; j < 21; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(primeralineat[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(primeralineat[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(100);
  }

delay(1000);

  float segundalineat[21][2] = {
    {148.2431361407, 90.0794149941},
    {145.3364164787, 87.0665696326},
    {142.3554885151, 84.0546891588},
    {139.314749241, 81.0373650877},
    {136.2281514351, 78.0094080607},
    {133.1088212238, 74.9667956738},
    {129.9687364946, 71.9066744418},
    {126.8184804549, 68.8274028938},
    {123.6670755575, 65.7286245907},
    {120.5218946889, 62.6113600112},
    {117.3886399888, 59.4781053111},
    {114.2713754093, 56.3329244425},
    {111.1725971062, 53.1815195451},
    {108.0933255582, 50.0312635054},
    {105.0332043262, 46.8911787762},
    {101.9905919393, 43.7718485649},
    {98.9626349123, 40.685250759},
    {95.9453108412, 37.6445114849},
    {92.9334303674, 34.6635835213},
    {89.9205850059, 31.7568638593},
    {86.8990235448, 28.9387730691}
  };

  for (int j = 0; j < 21; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(segundalineat[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(segundalineat[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(100);
  }

delay(1000);

  float tercerlineat[21][2] = {
    {86.8990235448, 28.9387730691},
    {88.384580402, 31.3831576126},
    {89.8232632638, 33.7862239647},
    {91.2140640342, 36.1529162809},
    {92.5538334948, 38.4847622396},
    {93.8415169891, 40.7870339806},
    {95.0740935942, 43.0616265457},
    {96.250492629, 45.3140497484},
    {97.3682654152, 47.5473501759},
    {98.4250898876, 49.7647487621},
    {99.4198702296, 51.9721599552},
    {100.349974881, 54.1723381896},
    {101.2142420803, 56.3716465983},
    {102.0104239935, 58.5742662606},
    {102.7363369161, 60.784791461},
    {103.3905383905, 63.010878727},
    {103.9487257015, 65.1673524335},
    {104.3409364157, 66.8931507964},
    {104.688010906, 68.6392661119},
    {104.9887651871, 70.4099814355},
    {105.2418912576, 72.2102248837}
  };

  for (int j = 0; j < 21; j++) {
    int microsegundos_m1 = map_grados_a_microsegundos(tercerlineat[j][0]);
    m1->writeMicroseconds(microsegundos_m1);
    int microsegundos_m2 = map_grados_a_microsegundos(tercerlineat[j][1]);
    m2->writeMicroseconds(microsegundos_m2);
    delay(100);
  }
}
/*_________________________________________________________________________________________________________________________________________________________________________________________________*/



void bajarLapiz(Servo *m3) {
  m3->write(140);
  delay(500);
  m3->write(130);
  delay(500);
  m3->write(120);
  delay(500);
  m3->write(110);
  delay(500);
  m3->write(100);
  delay(500);
  m3->write(90);
  delay(500);
}
