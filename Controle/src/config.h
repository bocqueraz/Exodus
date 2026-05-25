//à modifier pour éviter de répéter la définition des pins dans config.cpp et config.h, jsp comment

#pragma once
#pragma region Paramètres Controle des capteurs et moteurs
extern bool mode_libre; // par défaut en mode libre
extern const int sensibilite_capteur_force; // sensibilité des capteurs de force
extern const int degmin_moteur; // degré minimum de la position du moteur
extern const int degmax_moteur; // degré maximum de la position du moteur
extern const int RPM_AVANT_moteur;
extern const int RPM_ARRIERE_moteur;
#pragma endregion

#pragma region Paramètres du WiFi
extern const char* ssid;       // Nom du réseau Wi-Fi
extern const char* password; // Mot de passe du réseau Wi-Fi
#pragma endregion