#ifndef WIFI_STANDARD_H
#define WIFI_STANDARD_H

#include <vector>
#include <string>

class WiFiStandard {
public:
    enum class StandardType {
        WiFi4,
        WiFi5,
        WiFi6
    };

    // Constructor
    WiFiStandard(int numUsers, int numPackets, StandardType type);

    // Simulation methods
    void simulateTransmission();

    // Getter methods
    double getThroughput() const;
    double getAverageLatency() const;
    double getMaxLatency() const;

private:
    // Simulation parameters
    int m_numUsers;
    int m_numPackets;
    StandardType m_standardType;

    // Channel characteristics
    double m_bandwidth;
    int m_modulationType;
    double m_codingRate;
    double m_transmissionTime;

    // Simulation results
    double m_throughput;
    double m_averageLatency;
    double m_maxLatency;

    // Internal methods
    void initializeSimulation();
    double calculateSpectralEfficiency();
    double calculateTheoreticalMaxDataRate();

    // Transmission simulation methods for each standard
    void simulateWiFi4Transmission(std::vector<double>& latencies);
    void simulateWiFi5Transmission(std::vector<double>& latencies);
    void simulateWiFi6Transmission(std::vector<double>& latencies);

    // Utility methods
    double calculateAverageLatency(const std::vector<double>& latencies);
};

#endif // WIFI_STANDARD_H