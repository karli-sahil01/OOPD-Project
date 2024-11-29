#ifndef PACKET_H
#define PACKET_H

#include <string>

class Packet {
private:
    double size;      // Packet size in KB
    double timestamp; // Creation time of the packet
    std::string type; // Type of packet (e.g., "data", "ACK", "CSI")

public:
    Packet(double size, double timestamp, const std::string& type);

    double getSize() const;
    double getTimestamp() const;
    std::string getType() const;
};

#endif // PACKET_H
