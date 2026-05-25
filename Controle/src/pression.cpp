#include "pression.h"

Pression::Pression(int pin) : _pin(pin) {
    pinMode(_pin, INPUT);
}

bool Pression::capteurDetecte() {
    int valeur = ValeurCapteur();
    Logger::Log("Valeur du capteur de pression sur pin " + String(_pin) + ": " + String(valeur));
    if (valeur > _sensibilite_capteur_force) {
        return true; // Pression détectée
    } else {
        return false; // Pas de pression
    }
}

int Pression::ValeurCapteur() {
    return analogRead(_pin);
}