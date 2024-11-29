#ifndef PACKET_H
#define PACKET_H

#include <string>
#include <chrono>

class Packet {
public:
    // Constructors
    Packet();
    Packet(int size, std::string type);

    // Packet transmission methods
    bool transmit();
    void markTransmissionTime();

    // Getter methods
    int getSize() const;
    std::string getType() const;
    double getTransmissionLatency() const;

private:
    // Packet attributes
    int m_size;  // in bytes
    std::string m_type;

    // Transmission metadata
    std::chrono::steady_clock::time_point m_transmissionStart;
    std::chrono::steady_clock::time_point m_transmissionEnd;
    double m_transmissionLatency;
};

#endif // PACKET_H