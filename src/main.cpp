#include <Arduino.h>
#define BLYNK_PRINT Serial // лог работы модуля в мониторе
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include "math.h"
#define M_PI 3.141592653589793238462643

char auth[] = "9K4ztpDOvgK9-F70Ho494q84mrOkUQ1w";

int led = 4;
void setup()
{
  Serial.begin(9600);                           // See the connection status in Serial Monitor
  Blynk.begin(auth, "mikrot2", "Sparta130855"); //подключаем свою WIFI сеть
  pinMode(led, OUTPUT);
}

BLYNK_WRITE(V0)
{
  GpsParam gps(param);
  Serial.print("Lat: ");
  Serial.println(gps.getLat(), 8);
  Serial.print("Lon: ");
  Serial.println(gps.getLon(), 8);
  Serial.println();
  double x1 = gps.getLat();
  double y1 = gps.getLon();

  double x2 = 51.5048056;
  double y2 = 31.3343690;

  double dLat = (x2 - x1) * M_PI / 180.0;
  double dLon = (y2 - y1) * M_PI / 180.0;

  // convert to radians
  x1 = (x1)*M_PI / 180.0;
  x2 = (x2)*M_PI / 180.0;

  double a = pow(sin(dLat / 2), 2) +
             pow(sin(dLon / 2), 2) *
                 cos(x1) * cos(x2);
  double rad = 6371;
  double c = 2 * asin(sqrt(a));
  float distance = rad * c;
  
  Serial.println(distance,6);
  if(distance <= 0.005){
    Serial.println("Досягнуто місце призначення");
  }else{
    
    Serial.println("Місце призначення не досягнуто");
  }

}
void loop()
{
  Blynk.run();
}