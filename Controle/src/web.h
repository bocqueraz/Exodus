// ce fichier contient les pages HTML stockées en mémoire flash pour économiser la RAM ainsi que l'ensemble des définitions de la classe Web
// Ajout possible: graphique du poids porté par l'exosquellette sur chaque bras, ainsi que le niveau de charge, le temps de fonctionnement restant, etc... avec chart.js

// https://www.w3schools.com/js/js_graphics.asp

#include "logger.h"
#include <WebServer.h>
#include <LittleFS.h>

class Web {
    public :
        Web(const char *ssid, const char *password);
        static void tacheServeurWebStatic(void *parameter);

    private :
        WebServer server;
        const char *_ssid;
        const char *_password;
        void tacheServeurWeb();

};