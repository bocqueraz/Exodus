//à modifier pour éviter de répéter la définition des pins dans pin.cpp et pin.h, jsp comment

#pragma once
#pragma region definition des pins des capteurs de pression
extern const int CP1;
extern const int CP2;
extern const int CP3;
extern const int CP4;
// const int CP5;
// const int CP6;
// const int CP7;
// const int CP8;
#pragma endregion

#pragma region definition variables drivers VESC
extern const int RXD2; // pins pour la communication avec les VESCs
extern const int TXD2; 
#pragma endregion