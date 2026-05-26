// Fichier pour implémenter les fonctions de la classe Pression déclarée dans pression.h, pour pouvoir avoir un retour d'information sur les capteurs de pression.

#include "pression.h"

Pression::Pression(int pin) : _pin(pin) { // Initialisation du capteur de pression en définissant le mode du pin en entrée
    pinMode(_pin, INPUT);
}

bool Pression::capteurDetecte() { // Détecte si une pression est appliquée en comparant la valeur lue du capteur à une sensibilité définie
    int valeur = ValeurCapteur();
    Logger::Log("Valeur du capteur de pression sur pin " + String(_pin) + ": " + String(valeur));
    if (valeur > _sensibilite_capteur_force) {
        return true; // Pression détectée
    } else {
        return false; // Pas de pression
    }
}

int Pression::ValeurCapteur() { // Lit la valeur brute du capteur de pression
    return analogRead(_pin);
}