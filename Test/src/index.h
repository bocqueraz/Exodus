// ce fichier contient les pages HTML stockées en mémoire flash pour économiser la RAM
// Ajout possible: graphique du poids porté par l'exosquellette sur chaque bras, ainsi que le niveau de charge, le temps de fonctionnement restant, etc... avec chart.js

// https://www.w3schools.com/js/js_graphics.asp

#ifndef PAGES_H
#define PAGES_H

#include <pgmspace.h>

const char htmlIndex[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title id="titre">Controlleur Exodus</title>
</head>
<body>
    <div id="status">
    <h1>Controlleur Exodus</h1>
    <div class="boutonsControlleur">
    <button class="Allumer ButDebuter" href="/on">Allumer</button>
    <button class="Eteindre ButDebuter" href="/off">Eteindre</button>
    </div>
</div>
</body>
</html>
<script>
document.getElementsByClassName("Allumer")[0].onclick = function() {
    window.location.href = this.getAttribute("href");
};
document.getElementsByClassName("Eteindre")[0].onclick = function() {
    window.location.href = this.getAttribute("href");
};
</script>
<style>
#status {
    color: rgb(240, 232, 232);
    margin: auto;
    width: 50%;
    margin-top: 100px;
    padding: 20px;
    background-color: rgb(77, 77, 90);
    border-radius: 15px;
    text-align: center;
}

.boutonsControlleur {
    display: flex;
    flex-direction: column;
    gap: 15px;
}

.ButDebuter {
    color: rgb(240, 232, 232);
    border: none;
    border-radius: 10px;
    padding: 10px 24px;
    width: 100%;
    display: flex;
    justify-content: center;
    cursor: pointer;
    font-weight: bold;
}
.ButDebuter:hover {
    box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
}

.Allumer {
    background-color: rgb(89, 205, 89);
}
.Eteindre {
    background-color: rgb(205, 89, 89);
}
</style>
)rawliteral";

const char htmlOff[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Controlleur Exodus</title>
</head>
<body>
    <div id="status">
    <h1>La LED est eteinte</h1>
    <div class="boutonsControlleur">
    <button class="Allumer ButDebuter" href="/on">Allumer</button>
    </div>
</div>
</body>
</html>
<script>
document.getElementsByClassName("Allumer")[0].onclick = function() {
    window.location.href = this.getAttribute("href");
};
</script>
<style>
#status {
    color: rgb(240, 232, 232);
    margin: auto;
    width: 50%;
    margin-top: 100px;
    padding: 20px;
    background-color: rgb(77, 77, 90);
    border-radius: 15px;
    text-align: center;
}

.boutonsControlleur {
    display: flex;
    flex-direction: column;
    gap: 15px;
}

.ButDebuter {
    color: rgb(240, 232, 232);
    border: none;
    border-radius: 10px;
    padding: 10px 24px;
    width: 100%;
    display: flex;
    justify-content: center;
    cursor: pointer;
    font-weight: bold;
}
.ButDebuter:hover {
    box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
}
.Allumer {
    background-color: rgb(89, 205, 89);
}
</style>
)rawliteral";

const char htmlOn[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Controlleur Exodus</title>
</head>
<body>
    <div id="status">
    <h1>La LED est allumée</h1>
    <div class="boutonsControlleur">
    <button class="Eteindre ButDebuter" href="/off">Eteindre</button>
    </div>
</div>
</body>
</html>
<script>
document.getElementsByClassName("Eteindre")[0].onclick = function() {
    window.location.href = this.getAttribute("href");
};
</script>
<style>
#status {
    color: rgb(240, 232, 232);
    margin: auto;
    width: 50%;
    margin-top: 100px;
    padding: 20px;
    background-color: rgb(77, 77, 90);
    border-radius: 15px;
    text-align: center;
}

.boutonsControlleur {
    display: flex;
    flex-direction: column;
    gap: 15px;
}

.ButDebuter {
    color: rgb(240, 232, 232);
    border: none;
    border-radius: 10px;
    padding: 10px 24px;
    width: 100%;
    display: flex;
    justify-content: center;
    cursor: pointer;
    font-weight: bold;
}
.ButDebuter:hover {
    box-shadow:8px 8px 8px 0 rgba(16, 16, 16, 0.4);
}
.Eteindre {
    background-color: rgb(205, 89, 89);
}
</style>
)rawliteral";

#endif