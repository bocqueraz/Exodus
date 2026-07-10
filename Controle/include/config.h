//TODO: Modifier pour éviter de répéter la définition des pins dans config.cpp et config.h, jsp comment

//Fichier de configuration pour la déclaration des constantes utilisées dans le projet.
//Convention : toutes les constantes dans ce fichier sont écrites en minuscules 

#pragma once
#pragma region Paramètres Controle des capteurs et moteurs
extern bool mode_libre; // par défaut en mode libre
extern const int sensibilite_capteur_force; // sensibilité des capteurs de force
extern const int degmin_moteur; // degré minimum de la position du moteur
extern const int degmax_moteur; // degré maximum de la position du moteur
extern const int RPM_AVANT_moteur; // vitesse de rotation avant du moteur
extern const int RPM_ARRIERE_moteur; // vitesse de rotation arrière du moteur
extern const float FACTEUR_ASSISTANCE; // Paramètres de l'assistance (à régler empiriquement)
extern const float ZONE_MORTE;      // Courant minimum en Ampères avant que le moteur ne bouge (zone morte)
#pragma endregion

#pragma region Paramètres du WiFi
extern const char* ssid;       // Nom du réseau Wi-Fi
extern const char* password; // Mot de passe du réseau Wi-Fi
#pragma endregion

#pragma region CAN ID moteur Brushless
extern const int can_id_moteur_coude_droit; // ID pour le moteur du coude droit
extern const int can_id_moteur_coude_gauche; // ID pour le moteur du coude gauche
extern const int can_id_moteur_epaule_droit; // ID pour le moteur de l'épaule droite
extern const int can_id_moteur_epaule_gauche; // ID pour le moteur de l'épaule gauche
#pragma endregion