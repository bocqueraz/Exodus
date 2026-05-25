#pragma once
#include "config.h"

class MoteurBrushless {
    public:
        MoteurBrushless(int pin);
        void Tourner(bool senshoraire = true);
        void Arreter();

    private:
        VescUart _vesc;
        const int _pin;
        const int _degmin_moteur = degmin_moteur;
        const int _degmax_moteur = degmax_moteur;
        const int _RPM_AVANT_moteur = RPM_AVANT_moteur;
        const int _RPM_ARRIERE_moteur = RPM_ARRIERE_moteur;
};