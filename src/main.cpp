#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial // лог работы модуля в мониторе

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
  double a = sqrt(28);
  Serial.print("Lol: ");
  Serial.print(a);
  Serial.print("\n");

  GpsParam gps(param);
  Serial.print("Lat: ");
  Serial.println(gps.getLat(), 8);

  Serial.print("Lon: ");
  Serial.println(gps.getLon(), 8);

  Serial.println();
}

void loop()
{
  Blynk.run(); // All the Blynk Magic happens here...
}