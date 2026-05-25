//à modifier pour éviter de répéter la définition des pins dans config.cpp et config.h, jsp comment

#include "config.h"

#pragma region Paramètres Controle des capteurs et moteurs
bool mode_libre = false; // par défaut en mode libre
const int sensibilite_capteur_force = 500; // sensibilité des capteurs de force
const int degmin_moteur = 10; // degré minimum de la position du moteur
const int degmax_moteur = 100; // degré maximum de la position du moteur
const int RPM_AVANT_moteur = 2000;
const int RPM_ARRIERE_moteur = -2000;
#pragma endregion

#pragma region Paramètres du WiFi
const char* ssid = "Exodus";       // Nom du réseau Wi-Fi
const char* password = "Exodus25"; // Mot de passe du réseau Wi-Fi
#pragma endregion
