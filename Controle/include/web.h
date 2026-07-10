// Ce fichier contient les pages HTML stockées en mémoire flash pour économiser la RAM ainsi que l'ensemble des définitions de la classe Web
// TODO: rendre le site dynamique en y affichant les infos de l'Exodus en temps réel et  graphique du poids porté par l'exosquellette sur chaque bras, ainsi que le niveau de charge, le temps de fonctionnement restant, etc... avec chart.js

// https://www.w3schools.com/js/js_graphics.asp

#pragma once

#include "logger.h"
#include <WebServer.h>
#include <LittleFS.h>
#include "config.h"

class Web {
    public :
        Web(); // constructeur de la classe Web pour le serveur web en mode AP
        static void tacheServeurWebStatic(void* parameter); // fonction statique pour lancer la tâche du serveur web en mode AP

    private :
        WebServer server; // instance de la classe WebServer pour gérer le serveur web
        const char* _ssid = ssid; // Nom du réseau Wi-Fi pour le mode AP
        const char* _password = password; // Mot de passe du réseau Wi-Fi pour le mode AP
        void tacheServeurWeb(); // fonction pour la tâche du serveur web en mode AP
};