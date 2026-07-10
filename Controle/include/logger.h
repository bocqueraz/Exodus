// Déclaration de la classe Logger pour débugger facilement le projet.

#pragma once
#include <atomic>
#include <Arduino.h>

class Logger {
    private:
        static std::atomic_flag disponible; // Indique si le logger est disponible pour écrire un message, pour éviter les conflits d'écriture

    public:
        static void Log(const String &message); // Méthode statique pour enregistrer un message
};