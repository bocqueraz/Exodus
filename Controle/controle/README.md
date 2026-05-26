# Projet Controle PlatformIO

Ce sous-projet contient le code de l'ESP32 qui pilote le système de controle.
Il est développé avec PlatformIO et utilise le framework Arduino pour l'ESP32.

## Vue globale du code

L'architecture est volontairement simple et séparée par tâches :

- `src/main.cpp` contient la logique de l'exosquelette.
- `src/web.cpp` gère le point d'accès Wi-Fi et le serveur HTTP.
- `src/moteur.cpp` contient la logique de commande des moteurs brushless via VESC.
- `src/pression.cpp` lit les capteurs de pression.
- `src/logger.cpp` centralise les messages de log.
- `src/config.cpp` et `src/pin.cpp` regroupent la configuration du projet et l'affectation des pins.

Le dossier `lib/` du projet contient toutes les librairies customisées et utilisées par le code.

Le dossier `data/` du projet contient donc les fichiers qui seront embarqués dans la mémoire flash lors de la génération de l'image LittleFS.

## LittleFS et mémoire flash

LittleFS est le système de fichiers utilisé pour stocker les fichiers du site web sur l'ESP32.

Quand des fichiers de `data/` sont modifiés, supprimés ou ajoutés, il faut reconstruire puis réuploader l'image du système de fichiers vers l'ESP32.
Il est aussi possible d'effacer completement la mémoire flash de l'ESP32

### Via l'application

Dans PlatformIO, tu peux utiliser les tâches du projet :

- `Erase Flash` pour effacer entièrement la mémoire de l'ESP32.
- `Upload Filesystem Image` pour réécrire uniquement la partition LittleFS.

Le plus courant pour nettoyer les fichiers web est de supprimer les fichiers dans `data/`, puis de relancer l'upload du filesystem.

### Via les commandes

Effacer complètement la flash :

```bash
pio run -t erase
```

Reconstruire puis envoyer uniquement le système de fichiers LittleFS :

```bash
pio run -t buildfs
pio run -t uploadfs
```

## Initialiser le projet PlatformIO

### Via l'application VS Code / PlatformIO

1. Ouvre le dossier `Controle` dans VS Code.
2. Vérifie que l'extension PlatformIO est installée.
3. Ouvre PlatformIO Home puis le projet.
4. PlatformIO devrait s'occuper de tout le reste!
5. Il suffit ensuite d'utiliser les tâches PlatformIO pour compiler, flasher le firmware et envoyer le système de fichiers LittleFS.
