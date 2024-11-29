#include "User.h"
#include <random>

User::User(int userId, double signalStrength) 
    : m_userId(userId), 
      m_signalStrength(signalStrength),
      m_packetsSent(0),
      m_packetsSuccessful(0) {}

bool User::sendChannelStateInfo() {
    // Simulate channel state info transmission
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    return dis(gen) > 0.1;  // 90% success rate
}

bool User::transmitPacket() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    m_packetsSent++;
    
    // Success probability based on signal strength
    bool success = dis(gen) < m_signalStrength;
    
    if (success) {
        m_packetsSuccessful++;
    }

    return success;
}

int User::getUserId() const {
    return m_userId;
}

double User::getSignalStrength() const {
    return m_signalStrength;
}