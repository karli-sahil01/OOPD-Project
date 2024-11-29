#include "Packet.h"
#include <random>
#include <ctime>

Packet::Packet() 
    : m_size(1024),  // 1 KB default
      m_type("data"),
      m_transmissionLatency(0.0) {}

Packet::Packet(int size, std::string type)
    : m_size(size),
      m_type(type),
      m_transmissionLatency(0.0) {}

bool Packet::transmit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    // Simulate transmission success (85% success rate)
    bool success = dis(gen) > 0.15;

    if (success) {
        markTransmissionTime();
    }

    return success;
}

void Packet::markTransmissionTime() {
    // Simulate transmission time using clock
    clock_t start = clock();
    
    // Simulate some computation to represent transmission
    volatile double dummy = 0.0;
    for (int i = 0; i < 10000; ++i) {
        dummy += std::sin(i) * std::cos(i);
    }

    clock_t end = clock();

    // Calculate transmission latency
    m_transmissionLatency = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;  // Convert to milliseconds
}

int Packet::getSize() const {
    return m_size;
}

std::string Packet::getType() const {
    return m_type;
}

double Packet::getTransmissionLatency() const {
    return m_transmissionLatency;
}