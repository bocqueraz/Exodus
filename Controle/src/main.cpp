#include "main.h"

#pragma region Initialisation des instances globales
VescUart vesc;
Web web;
Pression BrasGaucheHaut = Pression(CP1);
#pragma endregion

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

  #pragma region lancement communication VESC
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // UART VESC (baudrate par défaut VESC)
  vesc.setSerialPort(&Serial2); // port de communication des VESC
  vesc.setDebugPort(&Serial); // port de debug des VESC
  Logger::Log("Communication série pour le VESC démarrée sur RXD2: " + String(RXD2) + " et TXD2: " + String(TXD2));
  #pragma endregion
}

void loop()
{
  Logger::Log(String(BrasGaucheHaut.capteurDetecte()));  
  delay(1000);
  
  // Il faudra implémenter la logique du controle du moteur ici
  // Il tournera sur le core 1 de l'ESP32
  // if(mode_libre){
  //   #pragma region Commande Mode Libre
  //   #pragma endregion
  // } else {
  //   #pragma region Commande Mode Assisté
  //   // si detection modification de l'ampérage du moteur alors:
  //     if(cp3 > sensibilite_capteur_force && vesc.data.pidPos > degmin_moteur){
  //       //descendre
  //       vesc.setRPM(RPM_AVANT_moteur);
  //     } else if(cp4 > sensibilite_capteur_force && vesc.data.pidPos < degmax_moteur){
  //       //monter
  //       vesc.setRPM(RPM_ARRIERE_moteur);
  //     }
  //   // sinon 
  //     if(cp1 > sensibilite_capteur_force){
  //       //descendre
  //     } else if(cp2 > sensibilite_capteur_force){
  //       //monter
  //     }
  //   #pragma endregion
  // }

  // if(vesc.getVescValues())
  // {
  //   if(vesc.data.pidPos > 100)
  //   {
  //     vesc.setRPM(RPM_AVANT_moteur);
  //   }
  //   else if(vesc.data.pidPos < 10)
  //   {
  //     vesc.setRPM(RPM_ARRIERE_moteur);
  //   }
  //   else
  //   {
  //     vesc.setRPM(0);
  //   }
  //   Logger(String(vesc.data.pidPos));
  // }
  // if(vesc.getVescValues())
  // {
  //   vesc.printVescValues();
  // }
  
  // vesc.setRPM(2000);
  // if(vesc.getVescValues())
  // {
  // Logger(String(vesc.data.rpm));
  // }
  // delay(200);

}
