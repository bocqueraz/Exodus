//TODO: Terminer de faire la fonction PrintData() pour afficher toutes les données du moteur et pas seulement la position, le RPM et la température du moteur.
// Déclaration de la classe MoteurBrushless pour pouvoir controller et avoir un retour d'information sur les moteurs brushless.

#pragma once
#include "config.h"
#include "pin.h"
#include "logger.h"
#include "VescUart.h"
#include <Arduino.h>

class MoteurBrushless {
    public:
        MoteurBrushless(int can_id); //Iniialisation du moteur avec son ID CAN
        void Turn(bool senshoraire = true); // Tourne le moteur dans le sens horaire ou antihoraire selon la position actuelle du moteur et les limites définies
        void Stop(); // Arrête le moteur et affiche la position actuelle du moteur
        int Position(); // Retourne la position actuelle du moteur en degrés
        void SetPosition(float deg); // Régler la position du moteur à une valeur spécifique en degrés
        void setPosition(float pos, uint8_t canId); // Régler la position du moteur à une valeur spécifique en degrés, avec un ID CAN pour les commandes relayées
        void PrintData(); // Affiche les données actuelles du moteur (position, RPM, température, etc.)
        void FollowMvt();

    private:
        VescUart _vesc; // Instance de la classe VescUart pour communiquer avec le VESC
        const int _can_id; // ID CAN du moteur pour les commandes relayées en communication CAN
        const int _degmin_moteur = degmin_moteur; // Degré minimum de la position du moteur. Sécurité pour éviter de dépasser les limites physiques d'un bras
        const int _degmax_moteur = degmax_moteur; // Degré maximum de la position du moteur. Sécurité pour éviter de dépasser les limites physiques d'un bras
        const int _RPM_AVANT_moteur = RPM_AVANT_moteur; // Vitesse de rotation avant du moteur pour faire tourner le moteur dans le sens horaire
        const int _RPM_ARRIERE_moteur = RPM_ARRIERE_moteur; // Vitesse de rotation arrière du moteur pour faire tourner le moteur dans le sens antihoraire
};