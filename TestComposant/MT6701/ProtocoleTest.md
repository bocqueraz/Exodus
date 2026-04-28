# Protocole de test
## Défaillances observées
- Le capteur renvoie 180° au bout d'un tour
- Comportement erratique
- Le driver moteur a du mal à opérer le moteur (peut-être lié à un autre comoposant)

## Comportement idéal
![Courbe ABZ sensée être obtenue](/TestComposant/MT6701/Img/SignalIdeal.png)
![Courbe du signal analog sur le pin 3](/TestComposant/MT6701/Img/AnalogIdeal.png)

## Orignes des défaillances possibles
- Composants corrompus (ex : puce, condensateur, diode)
- EEPROM reprogrammée

## Protocole n°1 :
A l'aide du banc de test du driver moteur, on vérifie à l'aide de l'oscilloscope le signal analogique sur le pin 3.

## Protocole n°2 :
A l'aide d'un arduino on vérifie le signal ABZ.