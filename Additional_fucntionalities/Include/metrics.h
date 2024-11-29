#ifndef METRICS_H
#define METRICS_H

#include <vector>
#include "packet.h"

class Metrics {
public:
    static double calculateThroughput(const std::vector<Packet>& transmittedPackets, double totalTime);
    static double calculateAverageLatency(const std::vector<Packet>& transmittedPackets);
    static double calculateMaximumLatency(const std::vector<Packet>& transmittedPackets);
};

#endif // METRICS_H
