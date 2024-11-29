#include "packet.h"

Packet::Packet(double size, double timestamp, const std::string& type)
    : size(size), timestamp(timestamp), type(type) {}

double Packet::getSize() const {
    return size;
}

double Packet::getTimestamp() const {
    return timestamp;
}

std::string Packet::getType() const {
    return type;
}
