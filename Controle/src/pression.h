#pragma once
#include "config.h"
#include <Arduino.h>
#include "logger.h"

class Pression {
    public:
        Pression(int pin);
        int capteurDetecte();

    private:
        const int _pin;
        const int _sensibilite_capteur_force = sensibilite_capteur_force;
        int ValeurCapteur();
};