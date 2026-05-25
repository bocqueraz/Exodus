#include "moteur.h"

MoteurBrushless::MoteurBrushless(int can_id) : _can_id(can_id) {
    // Initialisation du VESC et de la communication série
    #pragma region lancement communication VESC
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // UART VESC (baudrate par défaut VESC)
    _vesc.setSerialPort(&Serial2); // port de communication des VESC
    _vesc.setDebugPort(&Serial); // port de debug des VESC
    Logger::Log("Communication série pour le VESC " + String(_can_id) + " démarrée sur RXD2: " + String(RXD2) + " et TXD2: " + String(TXD2));
    #pragma endregion
}

void MoteurBrushless::Turn(bool senshoraire) {
    _vesc.getVescValues();
    if (senshoraire && MoteurBrushless::Position() > degmin_moteur) {
        _vesc.setRPM(_RPM_AVANT_moteur, _can_id);
    } else if(MoteurBrushless::Position() < degmax_moteur) {
        _vesc.setRPM(_RPM_ARRIERE_moteur, _can_id);
    } else {
        MoteurBrushless::Stop();
    }
    Logger::Log(String(_vesc.data.pidPos));
}

void MoteurBrushless::Stop() {
    _vesc.setRPM(0, _can_id);
    Logger::Log("Arrêt du moteur. Position: " + String(_vesc.data.pidPos));
}

int MoteurBrushless::Position() {
    return _vesc.data.pidPos;
}

void MoteurBrushless::SetPosition(float deg) {
    return setPosition(deg, 0);
}

void MoteurBrushless::setPosition(float pos, uint8_t canId) {
    int32_t index = 0;
    int payloadSize = (canId == 0 ? 5 : 7);
    uint8_t payload[payloadSize];

    if (canId != 0) {
        payload[index++] = COMM_FORWARD_CAN;  // Demande à relayer via CAN
        payload[index++] = canId;             // ID du VESC destinataire sur le bus CAN
    }

    payload[index++] = COMM_SET_POS;          // Commande pour régler la position
    buffer_append_int32(payload, (int32_t)(pos * 1000000.0), &index); // Position encodée

    _vesc.packSendPayload(payload, payloadSize);    // Envoie via UART
}

void MoteurBrushless::PrintData() {
    Logger::Log("Position actuelle du moteur: " + String(_vesc.data.pidPos));
    Logger::Log("RPM actuel du moteur: " + String(_vesc.data.rpm));
    Logger::Log("Température du moteur: " + String(_vesc.data.tempMotor));
    _vesc.printVescValues(); // à terminer d'afficher les données
}

void MoteurBrushless::FollowMvt() {

    if (_vesc.getVescValues()) {
    float effort = _vesc.data.avgMotorCurrent; 
    float angle = _vesc.data.pidPos;
    
    if (abs(effort) > ZONE_MORTE) {

        angle += (effort * FACTEUR_ASSISTANCE);
        SetPosition(angle);
        Logger::Log("Effort: "+String(effort)+" | Cible: "+String(angle));
    } else {
        Logger::Log("Effort: "+String(effort)+" | Zone Morte");
    }
  }

}