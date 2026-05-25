//à modifier pour éviter de répéter la définition des pins dans pin.cpp et pin.h, jsp comment
#include "pin.h"

#pragma region definition des pins des capteurs de pression
const int CP1 = 34; //definition des pins des capteurs de force/pression
const int CP2 = 3;
const int CP3 = 5;
const int CP4 = 7;
// const int CP5 = 8;
// const int CP6 = 9;
// const int CP7 = 10;
// const int CP8 = 11;
#pragma endregion

#pragma region definition variables drivers VESC
const int RXD2 = 16; // pins pour la communication avec les VESCs
const int TXD2 = 17; 
#pragma endregion