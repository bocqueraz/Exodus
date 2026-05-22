//Définition de la classe Web pour le serveur web en mode AP

#include "web.h"

#pragma region Tâche du Serveur Web en mode Point Accès (AP) | sur core 0

Web::Web(const char *ssid, const char *password) : server(80) {
    this->_ssid = ssid;
    this->_password = password;
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
  Logger::Log("Mot de passe du réseau: " + String(this->_password));
  Logger::Log("Adresse IP de l'AP: " + WiFi.softAPIP().toString());

  server.on("/", [this]() {
    File file = LITTLEFS.open("/index.html", "r");
    if (!file) {
      this->server.send(500, "text/plain", "Erreur: Fichier index.html absent");
      return;
    }
    this->server.streamFile(file, "text/html");
    file.close();
  });

  server.on("/dvbFavicon.png", [this]() {
    File file = LITTLEFS.open("/dvbFavicon.png", "r");
    if (!file) {
      this->server.send(500, "image/png", "Erreur: Fichier dvbFavicon.png absent");
      return;
    }
    this->server.streamFile(file, "image/png");
    file.close();
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