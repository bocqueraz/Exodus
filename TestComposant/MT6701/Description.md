# MT6701 : capteur d'angle

## Résumé
Le MT6701 est un capteur programmable d'angle utilisant un capteur à effet Hall. Le capteur fonctionne sur 3 modes de communication : ABZ, I2C et SSI Dans notre cas le capteur communiquera qu'en mode ABZ.

## Schéma électrique
![Schéma électrique de la pcb utilisée dans le projet](/TestComposant/MT6701/Img/SchemaElec.png)

|Pin|Nom|Fonctionnalité|
|---|----|--------------|
|1|VDD|Pin d'alimentation (entre 3V et 5V)|
|2|MODE|Permet de changer le mode de communication (LOW : ABZ, HIGH : I2C, SSI)|
|3|PWM/Analog|Renvoie le signal sous forme de signal PWM ou analogique dépend du pin MODE (LOW : Analog, HIGH : PWM)|
|4|GND||
|5|Push|Permet d'utilisé le capteur comme un bouton poussoir|
|6|A/U|En mode ABZ, correspond à la sortie A (I2C : SDA, SSI : DO)|
|7|B/V|En mode ABZ, correspond à la sortie B (I2C : SDL, SSI : CLK)|
|8|Z/W|En mode ABZ, correspond à la sortie Z (IZC : NC, SSI : CSN)|

## NOTE
Etant donnée que les pcb fonctionnent toutes en mode ABZ, les tests ne porteront uniquement sur ce mode et le signal analogique (Pin 3).

Le capteur est programmable en interface I2C, les données sont stockées dans une EEPROM, ce qui signifie que si la mémoire est corrompu, on ne peut rien y faire.

![Mémoire EEPROM](/TestComposant/MT6701/Img/EEPROM.png)