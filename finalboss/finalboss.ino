#include <DibujoFIME.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Servo.h>


const char* ssid = "TOLE";
const char* password = "hews2539";
WebServer server(80);
Servo *m1 = new Servo();
Servo *m2 = new Servo();
Servo *m3 = new Servo();

bool programaActivo = true;
bool isPaused = false;

void setup() {
  Serial.begin(115200);
  WiFi.softAP("TOLE", "hews2539");
  Serial.print("Dirección IP del ESP32: ");
  Serial.println(WiFi.softAPIP());
  m1->attach(18);
  m2->attach(19);
  m3->attach(21);
  server.on("/circle", handleCircle);
  server.on("/rectangle", handleRectangle);
  server.on("/triangle", handleTriangle);
  server.on("/square", handleSquare);
  server.on("/paused", handlePaused);
  server.on("/reanudar", handleReanudar);
  server.on("/finish", handleFinish);

  server.begin();
  posicioninicial(m1, m2, m3);
}

void loop() {
  if (!programaActivo) {
    // Finalizar programa y volver al inicio
    fin();
    return;
  }
  if (isPaused) {
    // El programa está en pausa
  } else {
    server.handleClient();
  }
}

void handleCircle() {
  if (programaActivo) {
   
    bajarLapiz(m3);
    dibujoCirculo(m1, m2, m3);
    dibujoCirculo(m1, m2, m3);
    delay(1000);
  }
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
   posicioninicial(m1, m2, m3);
     delay(1000);
}

void handleRectangle() {
  if (programaActivo) {
    bajarLapiz(m3);
    dibujoRectangulo(m1, m2, m3);
    dibujoRectangulo(m1, m2, m3);
    delay(1000);
  }
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
     posicioninicial(m1, m2, m3);
     delay(1000);
}

void handleTriangle() {
  if (programaActivo) {
    bajarLapiz(m3);
    dibujoTriangulo(m1, m2, m3);
    dibujoTriangulo(m1, m2, m3);
    delay(1000);
  }
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
     posicioninicial(m1, m2, m3);
     delay(1000);
}

void handleSquare() {
  if (programaActivo) {
    bajarLapiz(m3);
    dibujoCuadrado(m1, m2, m3);
    dibujoCuadrado(m1, m2, m3);
    delay(1000);
  }
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
     posicioninicial(m1, m2, m3);
     delay(1000);
}

void handlePaused() {
  pausar();
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
}

void handleReanudar() {
  reanudar();
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
}

void handleFinish() {
  fin();
  server.sendHeader("Location", "http://localhost/proyectoiset/form1.php");
  server.send(302, "text/plain", "");
}


void pausar() {
  isPaused = true;
}

void reanudar() {
  isPaused = false;
}

void fin() {
  programaActivo = false;
posicioninicial(m1,m2,m3);
}