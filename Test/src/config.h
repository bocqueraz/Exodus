#include <WiFi.h>
#pragma region Paramètres Exodus
bool mode_libre = false; // par défaut en mode libre
int sensibilite = 2000; // sensibilité des capteurs de force
int degmin = 10; // degré minimum de la position du moteur
int degmax = 100; // degré maximum de la position du moteur
#pragma endregion

#pragma region VESC
const int RPM_AVANT = 2000;
const int RPM_ARRIERE = -2000;
#pragma endregion

#pragma region WiFi
const char *ssid = "Exodus";       // Nom du réseau Wi-Fi
const char *password = "Exodus25"; // Mot de passe du réseau Wi-Fi
#pragma endregion

  #pragma region definition variables drivers VESC
  #define RXD2 16 // pins pour la communication avec les VESCs
  #define TXD2 17 
  #pragma endregion