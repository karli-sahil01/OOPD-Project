#include <iostream>
#include <iomanip>
#include "WiFiStandard.h"

void runSimulation(int numUsers, int numPackets, WiFiStandard::StandardType standardType) {
    WiFiStandard simulation(numUsers, numPackets, standardType);
    
    // Run simulation
    simulation.simulateTransmission();

    // Print results
    std::cout << "Simulation Results for "
              << (standardType == WiFiStandard::StandardType::WiFi4 ? "WiFi 4" :
                  standardType == WiFiStandard::StandardType::WiFi5 ? "WiFi 5" : "WiFi 6")
              << " with " << numUsers << " users:" << std::endl;
    
    std::cout << std::fixed << std::setprecision(2)
              << "Throughput: " << simulation.getThroughput() << " Mbps" << std::endl
              << "Average Latency: " << simulation.getAverageLatency() << " ms" << std::endl
              << "Maximum Latency: " << simulation.getMaxLatency() << " ms" << std::endl
              << std::endl;
}

int main() {
    // Simulation scenarios
    int packetCount = 100;

    // WiFi 4 Scenarios
    runSimulation(1, packetCount, WiFiStandard::StandardType::WiFi4);
    runSimulation(10, packetCount, WiFiStandard::StandardType::WiFi4);
    runSimulation(100, packetCount, WiFiStandard::StandardType::WiFi4);

    // WiFi 5 Scenarios
    runSimulation(1, packetCount, WiFiStandard::StandardType::WiFi5);
    runSimulation(10, packetCount, WiFiStandard::StandardType::WiFi5);
    runSimulation(100, packetCount, WiFiStandard::StandardType::WiFi5);

    // WiFi 6 Scenarios
    runSimulation(1, packetCount, WiFiStandard::StandardType::WiFi6);
    runSimulation(10, packetCount, WiFiStandard::StandardType::WiFi6);
    runSimulation(100, packetCount, WiFiStandard::StandardType::WiFi6);

    return 0;
}