#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

class User {
public:
    // Constructor
    User(int userId, double signalStrength);

    // Transmission methods
    bool sendChannelStateInfo();
    bool transmitPacket();

    // Getter methods
    int getUserId() const;
    double getSignalStrength() const;

private:
    // User attributes
    int m_userId;
    double m_signalStrength;

    // Transmission statistics
    int m_packetsSent;
    int m_packetsSuccessful;
};

#endif // USER_H