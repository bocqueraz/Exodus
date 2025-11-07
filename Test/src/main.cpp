#include <WiFi.h>
#include <WebServer.h>
#include "index.h"

#ifndef LED
#define LED 2 // pin de la LED intégrée pour ESP32
#endif

const char *ssid = "Exodus";       // Nom du réseau Wi-Fi
const char *password = "Exodus25"; // Mot de passe du réseau Wi-Fi

WebServer server(80);

void handleRoot()
{
  server.send(200, "text/html", htmlIndex); // page d'accueil
}

void handleOn()
{
  digitalWrite(LED, HIGH);
  server.send(200, "text/html", htmlOn); // page après allumage
}

void handleOff()
{
  digitalWrite(LED, LOW);
  server.send(200, "text/html", htmlOff); // page après extinction
}

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  Serial.print("Nom du réseau: ");
  Serial.println(ssid); // impression du nom du réseau
  Serial.print("Adresse IP de l'AP: ");
  Serial.println(WiFi.softAPIP()); // impression de l'adresse IP du site

  // Configuration du routeur web
  server.on("/", handleRoot);   // page d'accueil
  server.on("/on", handleOn);   // page après allumage
  server.on("/off", handleOff); // page après extinction
  server.begin();
  Serial.println("Site Internet démarré");
}

void loop()
{
  server.handleClient();
}
