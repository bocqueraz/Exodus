#include "main.h"

#pragma region Initialisation des instances globales
Web web;
Pression PressionBrasDroitDroit = Pression(PIN_PRESSION_BRAS_DROIT_DROIT);
Pression PressionBrasDroitGauche = Pression(PIN_PRESSION_BRAS_DROIT_GAUCHE);
Pression PressionBrasDroitHaut = Pression(PIN_PRESSION_BRAS_DROIT_HAUT);
Pression PressionBrasDroitBas = Pression(PIN_PRESSION_BRAS_DROIT_BAS);
MoteurBrushless MoteurCoudeDroit = MoteurBrushless(CAN_ID_MOTEUR_COUDE_DROIT);
MoteurBrushless MoteurCoudeGauche = MoteurBrushless(CAN_ID_MOTEUR_COUDE_GAUCHE);
MoteurBrushless MoteurEpauleDroit = MoteurBrushless(CAN_ID_MOTEUR_EPAULE_DROIT);
MoteurBrushless MoteurEpauleGauche = MoteurBrushless(CAN_ID_MOTEUR_EPAULE_GAUCHE);
#pragma endregion

bool modeLibre = true;

void setup()
{
  Serial.begin(115200); // Démarre la communication série pour le debug
  Serial.println("------------------------------");
  Serial.println("Démarrage du système...");
  
  #pragma region lancement du système de fichiers LittleFS
    if(!LITTLEFS.begin()){
      Logger::Log("Erreur lors de l'initialisation de LittleFS");
      return;
    }
    Logger::Log("LittleFS initialisé avec succès");
  #pragma endregion

  #pragma region lancement du site
  // Execute la tache sur le core 0
  xTaskCreatePinnedToCore(
    Web::tacheServeurWebStatic, // fonction (static wrapper)
    "ServeurWeb",    // nom
    10000,           // taille de la pile (bytes)
    &web,            // paramètres: pointer to the global instance
    1,               // priorité
    NULL,            // task handle (not used)
    0                // core
  );
  Logger::Log("Tâche Web lancée sur Core 0.");
  #pragma endregion
}

void loop()
{

  Logger::Log(String(PressionBrasDroitDroit.capteurDetecte()));  
  Logger::Log(String(PressionBrasDroitGauche.capteurDetecte()));  
  Logger::Log(String(PressionBrasDroitHaut.capteurDetecte()));  
  Logger::Log(String(PressionBrasDroitBas.capteurDetecte()));  

  if(modeLibre) {
    MoteurCoudeDroit.FollowMvt();
  } else {
    if(PressionBrasDroitDroit.capteurDetecte()) {
      MoteurCoudeDroit.Turn(true);
    } else if(PressionBrasDroitGauche.capteurDetecte()) {
      MoteurCoudeDroit.Turn(false);
    } else {
      MoteurCoudeDroit.Stop();
    }
  }

  delay(20);

}
