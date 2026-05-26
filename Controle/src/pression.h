// Déclaration de la classe Pression pour lire les données des capteurs de pression et détecter si une pression est appliquée ou non.

#pragma once
#include "config.h"
#include <Arduino.h>
#include "logger.h"

class Pression {
    public:
        Pression(int pin); // Initialisation du capteur de pression en définissant le pin en entrée
        bool capteurDetecte(); // Détecte si une pression est appliquée en comparant la valeur lue du capteur à une sensibilité définie

    private:
        const int _pin; // Pin de l'ESP32 auquel le capteur de pression est connecté
        const int _sensibilite_capteur_force = sensibilite_capteur_force; // Sensibilité des capteurs de force, définie dans config.h
        int ValeurCapteur(); // Lit la valeur brute du capteur de pression en utilisant analogRead() et retourne cette valeur pour être utilisée au déboggage
};