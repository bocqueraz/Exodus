
# Bibliothèques locales du projet Controle

Ce dossier regroupe les bibliothèques embarquées localement avec le projet PlatformIO.

## Bibliothèques présentes

### `LittleFS_esp32`

Cette bibliothèque fournit l'intégration de LittleFS pour l'ESP32.
Elle sert de couche d'accès au système de fichiers flash utilisé par le projet pour le moment uniquement pour stocker les fichiers web.

Cette copie locale reprend la base de la bibliothèque publiée, mais elle comprend quelques correctifs de bugs.

### `VescUart`

Cette bibliothèque gère la communication UART et CAN avec les VESCs.
Elle permet de lire la télémétrie du contrôleur moteur et d'envoyer les ordres depuis le code.

Par rapport à la bibliothèque publiée sur PlatformIO, cette version locale contient des fonctions modifiées ou ajoutées, notamment :
- la prise en charge de commandes avec identifiant CAN
- la possibilité d'avoir la position du moteur
- la correction de quelques bugs

## Architecture générale

Le code principal reste dans `Controle/src/`.
Les bibliothèques du dossier `lib/` sont utilisées par ce code pour séparer les responsabilités :
- gestion du système de fichiers local avec LittleFS
- communication série avec le VESC

Cette séparation permet de garder `src/` centré sur la logique applicative du projet, tandis que `lib/` concentre les dépendances techniques réutilisables.