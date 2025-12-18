// ce fichier contient les pages HTML stockées en mémoire flash pour économiser la RAM
// Ajout possible: graphique du poids porté par l'exosquellette sur chaque bras, ainsi que le niveau de charge, le temps de fonctionnement restant, etc... avec chart.js

// https://www.w3schools.com/js/js_graphics.asp

#ifndef PAGES_H
#define PAGES_H

#include <pgmspace.h>

const char htmlIndex[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exoskeleton Control Interface</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Rajdhani:wght@400;600;700&display=swap" rel="stylesheet">
    <style>
        :root {
            --primary-color: #ffffff;
            --secondary-color: #ced0d1;
            --accent-color: #051ccd;
            --text-color: #000000;
            --button-color: #3b469c;
            --button-hover: #03070d;
            --danger-color: #ef4444;
            --success-color: #22c55e;
            --warning-color: #f97316;
        }

        body {
            font-family: 'Rajdhani', sans-serif;
            background-color: var(--primary-color);
            color: var(--text-color);
            margin: 0;
            padding: 20px;
            background-image: url("file:///C:/Users/julia/OneDrive/Documents/exosquelette_site_interface_externe/IMG_7858.jpeg");
            background-size: cover;
            background-position: center;
            background-attachment: fixed;
        }

        h1 {
            text-align: center;
            color: var(--accent-color);
            font-size: 2.5rem;
            margin-bottom: 20px;
            text-shadow: 0 0 10px rgba(100, 100, 255, 0.5);
        }

        .container {
            display: flex;
            flex-wrap: wrap;
            gap: 20px;
            justify-content: center;
        }

        .section {
            background-color: var(--secondary-color);
            border-radius: 10px;
            padding: 20px;
            width: 300px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            border: 1px solid rgba(100, 126, 255, 0.2);
        }

        h2 {
            color: var(--accent-color);
            font-size: 1.5rem;
            margin-bottom: 15px;
            border-bottom: 1px solid rgba(100, 108, 255, 0.3);
            padding-bottom: 10px;
        }

        button {
            padding: 10px 20px;
            margin: 5px;
            font-size: 16px;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            color: #fff;
            font-family: 'Rajdhani', sans-serif;
            font-weight: 600;
            transition: all 0.3s ease;
            width: calc(50% - 10px);
        }

        #onButton {
            background-color: var(--success-color);
        }

        #onButton:hover {
            background-color: rgba(0, 0, 0, 0.8);
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
            height: 10px;
            background: rgba(100, 113, 255, 0.2);
            border-radius: 5px;
            margin-top: 5px;
        }

        input[type=range]::-webkit-slider-thumb {
            -webkit-appearance: none;
            width: 20px;
            height: 20px;
            background: var(--accent-color);
            border-radius: 50%;
            cursor: pointer;
        }

        #status {
            font-size: 18px;
            margin-top: 10px;
            text-align: center;
            font-weight: 600;
        }

        .sensor {
            margin-top: 10px;
            padding: 10px;
            background-color: rgba(103, 100, 255, 0.1);
            border-radius: 5px;
            border-left: 3px solid var(--accent-color);
        }

        canvas {
            background-color: rgba(0, 0, 0, 0.3);
            border-radius: 10px;
            margin-top: 20px;
            border: 1px solid rgba(110, 100, 255, 0.2);
        }

        .connection {
            margin-top: 10px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        #connectBtn {
            background-color: var(--button-color);
            width: 100%;
        }

        #connectBtn:hover {
            background-color: var(--button-hover);
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

        .exoskeleton-image {
            width: 100%;
            max-width: 300px;
            height: auto;
            margin: 20px auto;
            display: block;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            border: 1px solid rgba(110, 100, 255, 0.2);
        }
    </style>
</head>
<body>
            <div class="header">
            <img src="https://media.discordapp.net/attachments/1296821317898735646/1451249820542177402/Capture_decran_2025-12-17_160007.png?ex=69457d38&is=69442bb8&hm=db2ba0cc3d26f2c584ba4aa90527a7d28fdf9c7a44e270e93bb04ef2a30a87d8&=&format=webp&quality=lossless&width=354&height=349" alt="Logo" class="logo">
        </div>
    <h1>EXOSKELETON CONTROL INTERFACE</h1>
    <div class="container">
        <!-- Section Commandes ON/OFF et Emergency Stop -->
        <div class="section">
            <img class="exoskeleton-image" src="https://media.discordapp.net/attachments/1296821317898735646/1451249820273610875/IMG_7858.jpeg?ex=69457d38&is=69442bb8&hm=c769c8922fec1301107df35c09a9475fa50ca5d721146407f4b1d20cca16bec3&=&format=webp&width=885&height=541" alt="Exoskeleton">

            <h2>CONTROL</h2>
            <div style="display: flex; justify-content: space-between;">
                <button id="onButton">ON</button>
                <button id="offButton">OFF</button>
            </div>
            <button id="emergencyButton">EMERGENCY STOP</button>
            <div id="status">Status: OFF</div>
        </div>

        <!-- Section Réglage vitesse et assistance -->
        <div class="section">
            <h2>SETTINGS</h2>
            <label for="speedRange">Motor Speed:</label>
            <input type="range" id="speedRange" min="0" max="100" value="50">
            <span id="speedValue">50%</span>

            <label for="forceRange">Assistance Force:</label>
            <input type="range" id="forceRange" min="0" max="100" value="50">
            <span id="forceValue">50%</span>
        </div>

        <!-- Section Capteurs -->
        <div class="section">
            <h2>SENSORS</h2>
            <div class="sensor">Motor Temperature: <span id="tempMotor">0</span> °C</div>
            <div class="sensor">Battery Voltage: <span id="battery">0</span> V</div>
            <div class="sensor">Joint Angle: <span id="angle">0</span> °</div>
            <div class="sensor" id="alerts"></div>
        </div>

        <!-- Section Graphiques -->
        <div class="section">
            <h2>REAL-TIME GRAPHS</h2>
            <canvas id="graph" width="300" height="200"></canvas>
        </div>

        <!-- Section Connexion -->
        <div class="section">
            <h2>CONNECTION</h2>
            <div class="connection">
                <button id="connectBtn">Connect</button>
                <span id="connectionStatus" class="disconnected">Disconnected</span>
            </div>
        </div>
    </div>
</body>
</html>
)rawliteral";

// const char htmlIndex[] PROGMEM = R"rawliteral(
// <!DOCTYPE html>
// <html lang="en">
// <head>
//     <meta charset="UTF-8">
//     <meta name="viewport" content="width=device-width, initial-scale=1.0">
//     <title id="titre">Controlleur Exodus</title>
// </head>
// <body>
//     <div id="status">
//     <h1>Controlleur Exodus</h1>
//     <div class="boutonsControlleur">
//     <button class="Allumer ButDebuter" href="/on">Allumer</button>
//     <button class="Eteindre ButDebuter" href="/off">Eteindre</button>
//     </div>
// </div>
// </body>
// </html>
// <script>
// document.getElementsByClassName("Allumer")[0].onclick = function() {
//     window.location.href = this.getAttribute("href");
// };
// document.getElementsByClassName("Eteindre")[0].onclick = function() {
//     window.location.href = this.getAttribute("href");
// };
// </script>
// <style>
// #status {
//     color: rgb(240, 232, 232);
//     margin: auto;
//     width: 50%;
//     margin-top: 100px;
//     padding: 20px;
//     background-color: rgb(77, 77, 90);
//     border-radius: 15px;
//     text-align: center;
// }

// .boutonsControlleur {
//     display: flex;
//     flex-direction: column;
//     gap: 15px;
// }

// .ButDebuter {
//     color: rgb(240, 232, 232);
//     border: none;
//     border-radius: 10px;
//     padding: 10px 24px;
//     width: 100%;
//     display: flex;
//     justify-content: center;
//     cursor: pointer;
//     font-weight: bold;
// }
// .ButDebuter:hover {
//     box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
// }

// .Allumer {
//     background-color: rgb(89, 205, 89);
// }
// .Eteindre {
//     background-color: rgb(205, 89, 89);
// }
// </style>
// )rawliteral";

// const char htmlOff[] PROGMEM = R"rawliteral(
// <!DOCTYPE html>
// <html lang="en">
// <head>
//     <meta charset="UTF-8">
//     <meta name="viewport" content="width=device-width, initial-scale=1.0">
//     <title>Controlleur Exodus</title>
// </head>
// <body>
//     <div id="status">
//     <h1>La LED est eteinte</h1>
//     <div class="boutonsControlleur">
//     <button class="Allumer ButDebuter" href="/on">Allumer</button>
//     </div>
// </div>
// </body>
// </html>
// <script>
// document.getElementsByClassName("Allumer")[0].onclick = function() {
//     window.location.href = this.getAttribute("href");
// };
// </script>
// <style>
// #status {
//     color: rgb(240, 232, 232);
//     margin: auto;
//     width: 50%;
//     margin-top: 100px;
//     padding: 20px;
//     background-color: rgb(77, 77, 90);
//     border-radius: 15px;
//     text-align: center;
// }

// .boutonsControlleur {
//     display: flex;
//     flex-direction: column;
//     gap: 15px;
// }

// .ButDebuter {
//     color: rgb(240, 232, 232);
//     border: none;
//     border-radius: 10px;
//     padding: 10px 24px;
//     width: 100%;
//     display: flex;
//     justify-content: center;
//     cursor: pointer;
//     font-weight: bold;
// }
// .ButDebuter:hover {
//     box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
// }
// .Allumer {
//     background-color: rgb(89, 205, 89);
// }
// </style>
// )rawliteral";

// const char htmlOn[] PROGMEM = R"rawliteral(
// <!DOCTYPE html>
// <html lang="en">
// <head>
//     <meta charset="UTF-8">
//     <meta name="viewport" content="width=device-width, initial-scale=1.0">
//     <title>Controlleur Exodus</title>
// </head>
// <body>
//     <div id="status">
//     <h1>La LED est allumée</h1>
//     <div class="boutonsControlleur">
//     <button class="Eteindre ButDebuter" href="/off">Eteindre</button>
//     </div>
// </div>
// </body>
// </html>
// <script>
// document.getElementsByClassName("Eteindre")[0].onclick = function() {
//     window.location.href = this.getAttribute("href");
// };
// </script>
// <style>
// #status {
//     color: rgb(240, 232, 232);
//     margin: auto;
//     width: 50%;
//     margin-top: 100px;
//     padding: 20px;
//     background-color: rgb(77, 77, 90);
//     border-radius: 15px;
//     text-align: center;
// }

// .boutonsControlleur {
//     display: flex;
//     flex-direction: column;
//     gap: 15px;
// }

// .ButDebuter {
//     color: rgb(240, 232, 232);
//     border: none;
//     border-radius: 10px;
//     padding: 10px 24px;
//     width: 100%;
//     display: flex;
//     justify-content: center;
//     cursor: pointer;
//     font-weight: bold;
// }
// .ButDebuter:hover {
//     box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
// }
// .Eteindre {
//     background-color: rgb(205, 89, 89);
// }
// </style>
// )rawliteral";

#endif