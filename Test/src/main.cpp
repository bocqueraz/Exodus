#pragma region Librairies
#include <WiFi.h>
#include <WebServer.h>
#include "index.h"
#pragma endregion

#pragma region Logger
bool disponible = true;

void Logger(String message)
{
  if (disponible)
  {
    disponible = false;
    int coreID = xPortGetCoreID(); // récupère l'id du core

    Serial.print("[Core ");
    Serial.print(coreID);
    Serial.print("] ");
    Serial.println(message);

    disponible = true;
  }
}
#pragma endregion

#pragma region Tâche du Serveur Web en mode Point Accès (AP) | sur core 0
const char *ssid = "Exodus";       // Nom du réseau Wi-Fi
const char *password = "Exodus25"; // Mot de passe du réseau Wi-Fi

WebServer server(80);
void handleRoot() // page d'accueil
{
  server.send(200, "text/html", htmlIndex);
}

void tacheServeurWeb(void *parameter) // tâche du serveur web
{

  // Setup() de la tâche
  WiFi.softAP(ssid, password);
  Logger("Nom du réseau: " + String(ssid));
  Logger("Adresse IP de l'AP: " + WiFi.softAPIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Logger("Site Internet démarré");

  // Loop() de la tâche
  for (;;)
  {
    server.handleClient();

    delay(2); // permet d'éviter le watchdog timer reset | en gros de faire crash l'ESP32
  }
}
#pragma endregion

void setup()
{
  Serial.begin(115200);
  Serial.println("Démarrage du système...");
  // Execute la tache sur le core 0
  xTaskCreatePinnedToCore(
      tacheServeurWeb, // fonction
      "ServeurWeb",    // nom
      10000,           // taille de la pile (valeur arbitraire, je ne sais pas trop ce qu'il faut mettre)
      NULL,            // paramètres
      1,               // priorité
      NULL,            // ??? j'ai pas compris ce que sait
      0                // core
  );

  Logger("Tâche Web lancée sur Core 0.");
}

void loop()
{
  // Il faudra implémenter la logique du controle du moteur ici
  // Il tournera sur le core 1 de l'ESP32
}
