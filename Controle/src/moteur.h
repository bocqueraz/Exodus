#pragma once
#include "config.h"
#include "pin.h"
#include "logger.h"
#include "VescUart.h"
#include <Arduino.h>

class MoteurBrushless {
    public:
        MoteurBrushless(int can_id);
        void Turn(bool senshoraire = true);
        void Stop();
        int Position();
        void SetPosition(float deg);
        void setPosition(float pos, uint8_t canId);
        void PrintData();
        void FollowMvt();

    private:
        VescUart _vesc;
        const int _can_id;
        const int _degmin_moteur = degmin_moteur;
        const int _degmax_moteur = degmax_moteur;
        const int _RPM_AVANT_moteur = RPM_AVANT_moteur;
        const int _RPM_ARRIERE_moteur = RPM_ARRIERE_moteur;
};