#ifndef WIFI4_H
#define WIFI4_H

#include <vector>

// Forward declarations
class FrequencyChannel;
class AccessPoint;
class User;
class Packet;

// Packet class: Represents a data packet
class Packet {
public:
    static constexpr int SIZE_BITS = 8000; // 1 KB = 8000 bits
};

// FrequencyChannel class: Represents the frequency channel
class FrequencyChannel {
private:
    double bandwidth;
    int modulation;
    double codingRate;

public:
    FrequencyChannel(double bandwidth, int modulation, double codingRate);

    double getDataRate() const;
    double getTransmissionTime() const;
};

// User class: Represents a user in the network
class User {
private:
    FrequencyChannel &channel;
    double backoffTime;
    double latency;

    double generateBackoff(int numUsers);

public:
    User(FrequencyChannel &channel);
    void transmit(int numUsers);

    double getBackoffTime() const;
    double getLatency() const;
};

// AccessPoint class: Represents the WiFi Access Point
class AccessPoint {
private:
    FrequencyChannel channel;
    std::vector<User> users;

public:
    AccessPoint(double bandwidth, int modulation, double codingRate);
    void simulate(int numUsers);
};

#endif // WIFI4_H
