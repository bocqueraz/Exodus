#pragma region Librairies
#include <WiFi.h>
#include <WebServer.h>
#include "index.h"
#include "VescUart.h"
#pragma endregion

#pragma region Paramètres Exodus
bool mode_libre = false; // par défaut en mode libre
int sensibilite = 2000; // sensibilité des capteurs de force
int degmin = 10; // degré minimum de la position du moteur
int degmax = 100; // degré maximum de la position du moteur
#pragma endregion

#pragma region VESC
VescUart vesc;
const int RPM_AVANT = 2000;
const int RPM_ARRIERE = -2000;

#define CP1 4 //definition des pins des capteurs de force/pression
#define CP2 3
#define CP3 5
#define CP4 7 
// #define CP5 8
// #define CP6 9
// #define CP7 10 
// #define CP8 11
const int cp1 = analogRead(CP1);
const int cp2 = analogRead(CP2);
const int cp3 = analogRead(CP3);
const int cp4 = analogRead(CP4);
// const int cp5 = analogRead(CP5);
// const int cp6 = analogRead(CP6);
// const int cp7 = analogRead(CP7);
// const int cp8 = analogRead(CP8);
#pragma endregion

#pragma region Logger
bool disponible = true;

void Logger(String message)
{
  if (disponible)
  {
    disponible = false;
    int coreID = xPortGetCoreID(); // récupère l'id du core

    Serial.print("[Core ");
    Serial.print(coreID);
    Serial.print("] ");
    Serial.println(message);

    disponible = true;
  }
}
#pragma endregion

#pragma region Tâche du Serveur Web en mode Point Accès (AP) | sur core 0
const char *ssid = "Exodus";       // Nom du réseau Wi-Fi
const char *password = "Exodus25"; // Mot de passe du réseau Wi-Fi

WebServer server(80);
void handleRoot() // page d'accueil
{
  server.send(200, "text/html", htmlIndex);
}

void tacheServeurWeb(void *parameter) // tâche du serveur web
{

  // Setup() de la tâche
  WiFi.softAP(ssid, password);
  Logger("Nom du réseau: " + String(ssid));
  Logger("Adresse IP de l'AP: " + WiFi.softAPIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Logger("Site Internet démarré");

  // Loop() de la tâche
  for (;;)
  {
    server.handleClient();

    delay(2); // permet d'éviter le watchdog timer reset | en gros de faire crash l'ESP32
  }
}
#pragma endregion

void setup()
{
  #pragma region deifnition variables drivers VESC
  #define RXD2 16 // pins pour la communication avec les VESCs
  #define TXD2 17 
  #pragma endregion
  
  #pragma region lancement du site
  Serial.begin(115200); // Démarre la communication série pour le debug
  Serial.println("------------------------------");
  Serial.println("Démarrage du système...");

  // Execute la tache sur le core 0
  xTaskCreatePinnedToCore(
      tacheServeurWeb, // fonction
      "ServeurWeb",    // nom
      10000,           // taille de la pile (valeur arbitraire, je ne sais pas trop ce qu'il faut mettre)
      NULL,            // paramètres
      1,               // priorité
      NULL,            // ??? j'ai pas compris ce que sait
      0                // core
  );

  Logger("Tâche Web lancée sur Core 0.");
  #pragma endregion

  #pragma region lancement communication VESC
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // UART VESC (baudrate par défaut VESC)
  vesc.setSerialPort(&Serial2); // port de communication des VESC
  vesc.setDebugPort(&Serial); // port de debug des VESC
  Logger("Communication série pour le VESC démarrée sur RXD2: " + String(RXD2) + " et TXD2: " + String(TXD2));
  #pragma endregion
}

void loop()
{
  // Il faudra implémenter la logique du controle du moteur ici
  // Il tournera sur le core 1 de l'ESP32
  if(mode_libre){
    #pragma region Commande Mode Libre
    #pragma endregion
  } else {
    #pragma region Commande Mode Assisté
    // si detection modification de l'ampérage du moteur alors:
      if(cp3 > sensibilite && vesc.data.pidPos > degmin){
        //descendre
        vesc.setRPM(RPM_AVANT);
      } else if(cp4 > sensibilite && vesc.data.pidPos < degmax){
        //monter
        vesc.setRPM(RPM_ARRIERE);
      }
    // sinon 
      if(cp1 > sensibilite){
        //descendre
      } else if(cp2 > sensibilite){
        //monter
      }
    #pragma endregion
  }

  // if(vesc.getVescValues())
  // {
  //   if(vesc.data.pidPos > 100)
  //   {
  //     vesc.setRPM(RPM_AVANT);
  //   }
  //   else if(vesc.data.pidPos < 10)
  //   {
  //     vesc.setRPM(RPM_ARRIERE);
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

  /////////////////////////////////////////////////////////////////////////

  // const int fsrPin = 34;    // GPIO 34 est une entrée analogique (ADC1)
  // int fsrReading;    
  // bool test = true;  
  // fsrReading = analogRead(fsrPin); 

  // Serial.print("Valeur brute ESP32 : ");
  // Serial.print(fsrReading);

  // //Ajustement des seuils pour la résolution 12 bits
  // if (fsrReading < 100) {
  //   Serial.println(" -> État : Vide");
  // } else if (fsrReading < 1000) {
  //   Serial.println(" -> État : Pression légère");
  // } else if (fsrReading < 2500) {
  //   Serial.println(" -> État : Pression moyenne");
  // } else {
  //   Serial.println(" -> État : Pression forte !");
  //   if(test){
  //     vesc.setRPM(2000);
  //     test = false;
  //   }
  // }

  // delay(2); // Lecture plus rapide pour plus de réactivité

  /////////////////////////////////////////////////////////////////////////

}
