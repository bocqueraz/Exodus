//à modifier pour éviter de répéter la définition des pins dans pin.cpp et pin.h, jsp comment

#pragma once
#pragma region definition des pins des capteurs de pression
extern const int PIN_PRESSION_BRAS_DROIT_DROIT; // Pin pour le capteur de pression du coude droit
extern const int PIN_PRESSION_BRAS_DROIT_GAUCHE; // Pin pour le capteur de pression du coude gauche
extern const int PIN_PRESSION_BRAS_DROIT_HAUT; // Pin pour le capteur de pression de l'épaule droite
extern const int PIN_PRESSION_BRAS_DROIT_BAS; // Pin pour le capteur de pression de l'épaule gauche
#pragma endregion

#pragma region definition variables drivers VESC
extern const int RXD2; // pins pour la communication avec les VESCs
extern const int TXD2; 
#pragma endregion