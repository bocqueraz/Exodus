// ce fichier contient les pages HTML stockées en mémoire flash pour économiser la RAM ainsi que l'ensemble des définitions de la classe Web
// Ajout possible: graphique du poids porté par l'exosquellette sur chaque bras, ainsi que le niveau de charge, le temps de fonctionnement restant, etc... avec chart.js

// https://www.w3schools.com/js/js_graphics.asp

#include <WebServer.h>

class Web {
    public :
        Web(const char *ssid, const char *password);
        static void tacheServeurWebStatic(void *parameter);

    private :
        WebServer server;
        const char *_ssid;
        const char *_password;
        void _handleRoot();
        void tacheServeurWeb();

};

const char _htmlIndex[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DVB | Exodus</title>
    <link rel="icon" type="image/png" href="https://davincibot.fr/favicon.png">
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Rajdhani:wght@400;600;700&display=swap" rel="stylesheet">
    <style>
        :root {
            --texte: rgb(255, 255, 255);
            --DVB-background: rgb(1, 1, 40);
            --DVB-secondaire: rgb(153, 170, 255);
            --danger-color: rgb(239, 68, 68);
            --success-color: rgb(34, 197, 94);
        }

        body {
            font-family: 'Rajdhani', sans-serif;
            background-color: var(--DVB-background);
            color: var(--texte);
            margin: 0;
            padding: 20px;
            background-size: cover;
            background-position: center;
            background-attachment: fixed;
        }

        h1 {
            text-align: center;
            color: var(--texte);
            font-size: 2.5rem;
            margin-bottom: 20px;
            text-shadow: 0 0 10px rgba(179, 194, 255, 0.5);
        }

        .container {
            display: flex;
            flex-wrap: wrap;
            gap: 20px;
            justify-content: center;
        }

        .section {
            background-color: var(--DVB-background);
            border-radius: 10px;
            padding: 20px;
            width: 300px;
            box-shadow: 3px 3px 3px var(--DVB-secondaire);
            border: 3px solid rgb(153 170 255 / 0.8);
        }

        h2 {
            color: var(--texte);
            font-size: 1.5rem;
            margin-bottom: 15px;
            border-bottom: 3px solid var(--DVB-secondaire);
            padding-bottom: 10px;
        }

        button {
            padding: 10px 20px;
            margin: 5px;
            font-size: 16px;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            color: var(--texte);
            font-family: 'Rajdhani', sans-serif;
            font-weight: 600;
            transition: all 0.3s ease;
            width: calc(50% - 10px);
        }

        #onButton {
            background-color: var(--success-color);
        }

        #onButton:hover {
            background-color: rgba(34, 197, 94, 0.8);
        }

        #offButton {
            background-color: var(--danger-color);
        }

        #offButton:hover {
            background-color: rgba(239, 68, 68, 0.8);
        }

        #emergencyButton {
            background-color: var(--danger-color);
            width: 100%;
            font-size: 18px;
            padding: 15px;
            margin-top: 10px;
        }

        #emergencyButton:hover {
            background-color: rgba(239, 68, 68, 0.8);
            transform: scale(1.02);
        }

        label {
            display: block;
            margin-top: 10px;
            font-weight: 600;
        }

        input[type=range] {
            width: 100%;
            height: 5px;
        }

        input[type=range]::-webkit-slider-thumb {
            cursor: pointer;
        }

        #status {
            display: flex;
            justify-content: center;
            font-size: 18px;
            margin-top: 20px;
            font-weight: 600;
        }

        .sensor {
            margin-top: 10px;
            padding: 10px;
            background-color: rgba(153, 170, 255, 0.4);
            border-radius: 5px;
            border-left: 5px solid var(--DVB-secondaire);
            font-weight: 600;
        }

        canvas {
            background-color: var(--DVB-background);
            border-radius: 10px;
            margin-top: 20px;
            border: 3px solid var(--DVB-secondaire);
        }

        .connection {
            margin-top: 10px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        #connectBtn {
            background-color: var(--DVB-secondaire);
            width: 100%;
        }

        #connectBtn:hover {
            background-color: rgba(153, 170, 255, 0.8);
            transform: scale(1.02);
        }

        #connectionStatus {
            margin-top: 10px;
            font-weight: 600;
        }

        .connected {
            color: var(--success-color);
        }

        .disconnected {
            color: var(--danger-color);
        }

        /* .exoskeleton-image {
            width: 100%;
            max-width: 300px;
            height: auto;
            margin: 20px auto;
            display: block;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            border: 1px solid rgba(110, 100, 255, 0.2);
        } */
    </style>
</head>
<body>
            <!-- <div class="header">
            <img src="https://media.discordapp.net/attachments/1296821317898735646/1451249820542177402/Capture_decran_2025-12-17_160007.png?ex=69457d38&is=69442bb8&hm=db2ba0cc3d26f2c584ba4aa90527a7d28fdf9c7a44e270e93bb04ef2a30a87d8&=&format=webp&quality=lossless&width=354&height=349" alt="Logo" class="logo">
        </div> -->
    <h1>Interface de Contrôle Exodus</h1>
    <br>
    <div class="container">
        <div class="section">
            <!-- <img class="exoskeleton-image" src="https://media.discordapp.net/attachments/1296821317898735646/1451249820273610875/IMG_7858.jpeg?ex=69457d38&is=69442bb8&hm=c769c8922fec1301107df35c09a9475fa50ca5d721146407f4b1d20cca16bec3&=&format=webp&width=885&height=541" alt="Exoskeleton"> -->
            <h2>Contrôles</h2>
            <div style="display: flex; justify-content: space-between;">
                <button id="onButton">ON</button>
                <button id="offButton">OFF</button>
            </div>
            <button id="emergencyButton">ARRÊT D'URGENCE</button>
            <div id="status">Status: OFF</div>
        </div>

        <div class="section">
            <h2>Paramètres</h2>
            <label for="speedRange">Vitesse du moteur :</label>
            <input type="range" id="speedRange" min="0" max="100" value="50">
            <span id="speedValue">50%</span>

            <label for="forceRange">Force d'assistance :</label>
            <input type="range" id="forceRange" min="0" max="100" value="50">
            <span id="forceValue">50%</span>
        </div>

        <div class="section">
            <h2>Capteurs</h2>
            <div class="sensor">Température du moteur : <span id="tempMotor">0</span> °C</div>
            <div class="sensor">Tension de la batterie : <span id="battery">0</span> V</div>
            <div class="sensor">Angle de l'articulation : <span id="angle">0</span> °</div>
            <div class="sensor">Test</div>
        </div>

        <div class="section">
            <h2>Graphiques</h2>
            <canvas id="graph" width="300" height="200"></canvas>
        </div>

        <div class="section">
            <h2>Connexion</h2>
            <div class="connection">
                <button id="connectBtn">Connexion</button>
                <span id="connectionStatus" class="disconnected">Déconnecté</span>
            </div>
        </div>
    </div>
</body>
</html>
)rawliteral";