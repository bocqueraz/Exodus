//Définition de la classe Web pour le serveur web en mode AP

#include "web.h"

#pragma region Tâche du Serveur Web en mode Point Accès (AP) | sur core 0

Web::Web(const char *ssid, const char *password) : server(80) {
    this->_ssid = ssid;
    this->_password = password;
}

void Web::_handleRoot() // page d'accueil
{
  server.send(200, "text/html", _htmlIndex);
}

void Web::tacheServeurWebStatic(void *parameter)
{
  Web *instance = static_cast<Web *>(parameter);
  if (instance)
  {
    instance->tacheServeurWeb();
  }
  vTaskDelete(NULL);
}

void Web::tacheServeurWeb() // tâche du serveur web (instance)
{
  // Setup() de la tâche
  WiFi.softAP(this->_ssid, this->_password);
  Logger::Log("Nom du réseau: " + String(this->_ssid));
  Logger::Log("Adresse IP de l'AP: " + WiFi.softAPIP().toString());

  server.on("/", HTTP_GET, [this]() {
    this->_handleRoot();
  });
  server.begin();
  Logger::Log("Site Internet démarré");

  // Loop() de la tâche
  for (;;)
  {
    server.handleClient();

    delay(2); // permet d'éviter le watchdog timer reset | en gros de faire crash l'ESP32
  }
}

#pragma endregion