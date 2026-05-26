//TODO: Modifier pour éviter de répéter la définition des pins dans config.cpp et config.h, jsp comment

//Fichier de configuration pour la définition des constantes utilisées dans le projet.

#include "config.h"

#pragma region Paramètres Controle des capteurs et moteurs
bool mode_libre = false; // par défaut en mode libre
const int sensibilite_capteur_force = 25; // sensibilité des capteurs de force
const int degmin_moteur = 10; // degré minimum de la position du moteur
const int degmax_moteur = 100; // degré maximum de la position du moteur
const int RPM_AVANT_moteur = 2000; // vitesse de rotation avant du moteur
const int RPM_ARRIERE_moteur = -2000; // vitesse de rotation arrière du moteur
const float FACTEUR_ASSISTANCE = 0.5; // Vitesse à laquelle le moteur vous accompagne
const float ZONE_MORTE = 2.0;      // Courant minimum en Ampères avant que le moteur ne bouge (zone morte)
#pragma endregion

#pragma region Paramètres du WiFi
const char* ssid = "Exodus";       // Nom du réseau Wi-Fi
const char* password = "Exodus25"; // Mot de passe du réseau Wi-Fi
#pragma endregion

#pragma region CAN ID moteur Brushless
const int can_id_moteur_coude_droit = 0; // ID pour le moteur du coude droit
const int can_id_moteur_coude_gauche = 1; // ID pour le moteur du coude gauche
const int can_id_moteur_epaule_droit = 2; // ID pour le moteur de l'épaule droite
const int can_id_moteur_epaule_gauche = 3; // ID pour le moteur de l'épaule gauche
#pragma endregion