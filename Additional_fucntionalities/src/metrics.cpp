#include "metrics.h"
#include <numeric>
#include <algorithm>

double Metrics::calculateThroughput(const std::vector<Packet>& transmittedPackets, double totalTime) {
    double totalData = 0.0;
    for (const Packet& packet : transmittedPackets) {
        totalData += packet.getSize() * 8 * 1024; // Convert KB to bits
    }
    return totalData / (totalTime * 1e6); // Mbps
}

double Metrics::calculateAverageLatency(const std::vector<Packet>& transmittedPackets) {
    if (transmittedPackets.empty()) return 0.0;

    double totalLatency = 0.0;
    for (const Packet& packet : transmittedPackets) {
        totalLatency += packet.getTimestamp();
    }
    return totalLatency / transmittedPackets.size();
}

double Metrics::calculateMaximumLatency(const std::vector<Packet>& transmittedPackets) {
    if (transmittedPackets.empty()) return 0.0;

    double maxLatency = 0.0;
    for (const Packet& packet : transmittedPackets) {
        maxLatency = std::max(maxLatency, packet.getTimestamp());
    }
    return maxLatency;
}
