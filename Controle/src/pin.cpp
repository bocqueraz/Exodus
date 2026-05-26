//TODO: modifier pour éviter de répéter la définition des pins dans pin.cpp et pin.h, jsp comment
#include "pin.h"

#pragma region definition des pins des capteurs de pression
const int PIN_PRESSION_BRAS_DROIT_DROIT = 34; // Pin pour le capteur de pression du coude droit
const int PIN_PRESSION_BRAS_DROIT_GAUCHE = 35; // Pin pour le capteur de pression du coude gauche
const int PIN_PRESSION_BRAS_DROIT_HAUT = 32; // Pin pour le capteur de pression de l'épaule droite
const int PIN_PRESSION_BRAS_DROIT_BAS = 33; // Pin pour le capteur de pression de l'épaule gauche

#pragma endregion

#pragma region definition variables drivers VESC
const int RXD2 = 16; // pins pour la communication avec les VESCs
const int TXD2 = 17; // pins pour la communication avec les VESCs
#pragma endregion