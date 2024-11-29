#include <iostream>
#include "access_point.h"
#include "user.h"
#include "packet.h"
#include "frequency_channel.h"
#include "wifi4_csma_ca.h"
#include "wifi5_mu_mimo.h"
#include "wifi6_ofdma.h"
#include "metrics.h"

int main() {
    // Create Access Point and Users
    AccessPoint ap(1, 20.0, "256-QAM", 5.0 / 6.0);
    User user1(101), user2(102);
    ap.connectUser(&user1);
    ap.connectUser(&user2);

    // Create Packets
    Packet packet1(1.0, 0.01, "data");
    Packet packet2(0.2, 0.02, "CSI");

    // Test Broadcasting
    ap.broadcast(packet1);

    // Frequency Channel Simulation
    FrequencyChannel channel(20.0, 10);
    channel.allocate(2);

    // WiFi 4 CSMA/CA Simulation
    WiFi4 wifi4(&ap, {&user1, &user2});
    wifi4.simulate();

    // WiFi 5 MU-MIMO Simulation
    WiFi5 wifi5(&ap, {&user1, &user2});
    wifi5.simulate();

    // WiFi 6 OFDMA Simulation
    WiFi6 wifi6(&channel, {&user1, &user2});
    wifi6.simulate();

    // Metrics Calculation (for testing purposes)
    std::vector<Packet> packets = {packet1, packet2};
    double throughput = Metrics::calculateThroughput(packets, 10.0); // Example time: 10 seconds
    double avgLatency = Metrics::calculateAverageLatency(packets);
    double maxLatency = Metrics::calculateMaximumLatency(packets);

    std::cout << "Throughput: " << throughput << " Mbps\n";
    std::cout << "Average Latency: " << avgLatency << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";

    return 0;
}
