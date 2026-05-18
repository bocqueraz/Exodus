//permet de faire du logging en affichant l'id du core qui affiche le message

#include "logger.h"

std::atomic_flag Logger::disponible = ATOMIC_FLAG_INIT; // token pour éviter que les messages de log de différents cores s'entremêlent et deviennent illisibles

void Logger::Log(String message)
{
  while (disponible.test_and_set()) // essaye de prendre le token, si il est déjà pris, attend et réessaie
  {
    yield(); 
  }

  int coreID = xPortGetCoreID(); // récupère l'id du core

  Serial.print("[Core ");
  Serial.print(coreID);
  Serial.print("] ");
  Serial.println(message);

  disponible.clear(); // rend le token
}