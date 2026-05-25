#include "pression.h"

Pression::Pression(int pin) : _pin(pin) {
    pinMode(_pin, INPUT);
}

int Pression::capteurDetecte() {
    int valeur = ValeurCapteur();
    Logger::Log("Valeur du capteur de pression sur pin " + String(_pin) + ": " + String(valeur));
    if (valeur > _sensibilite_capteur_force) {
        return 1; // Pression détectée
    } else {
        return 0; // Pas de pression
    }
}

int Pression::ValeurCapteur() {
    return analogRead(_pin);
}