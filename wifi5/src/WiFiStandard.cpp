// WiFiStandard.cpp
#include "WiFiStandard.h"
#include <cmath>
#include <algorithm>
#include <random>

WiFiStandard::WiFiStandard(int numUsers, int numPackets, StandardType type) 
    : m_numUsers(numUsers), m_numPackets(numPackets), m_standardType(type) {
    initializeSimulation();
}

void WiFiStandard::initializeSimulation() {
    // Initialize simulation parameters based on standard type
    switch(m_standardType) {
        case StandardType::WiFi4:
            m_bandwidth = 20.0;  // MHz
            m_modulationType = 256;  // 256-QAM
            m_codingRate = 5.0 / 6.0;
            m_transmissionTime = 1.0;  // ms
            break;
        case StandardType::WiFi5:
            m_bandwidth = 20.0;
            m_modulationType = 256;
            m_codingRate = 5.0 / 6.0;
            m_transmissionTime = 15.0;  // ms for parallel transmission
            break;
        case StandardType::WiFi6:
            m_bandwidth = 20.0;
            m_modulationType = 256;
            m_codingRate = 5.0 / 6.0;
            m_transmissionTime = 5.0;  // ms for OFDMA
            break;
    }
}

double WiFiStandard::calculateSpectralEfficiency() {
    return std::log2(m_modulationType) * m_codingRate;
}

double WiFiStandard::calculateTheoreticalMaxDataRate() {
    return m_bandwidth * calculateSpectralEfficiency();
}

void WiFiStandard::simulateTransmission() {
    // Reset metrics
    m_throughput = 0.0;
    m_averageLatency = 0.0;
    m_maxLatency = 0.0;

    std::vector<double> latencies;

    switch(m_standardType) {
        case StandardType::WiFi4:
            simulateWiFi4Transmission(latencies);
            break;
        case StandardType::WiFi5:
            simulateWiFi5Transmission(latencies);
            break;
        case StandardType::WiFi6:
            simulateWiFi6Transmission(latencies);
            break;
    }

    // Calculate final metrics
    if (!latencies.empty()) {
        m_averageLatency = calculateAverageLatency(latencies);
        m_maxLatency = *std::max_element(latencies.begin(), latencies.end());
    }
}

void WiFiStandard::simulateWiFi4Transmission(std::vector<double>& latencies) {
    // WiFi 4 - Sequential transmission with backoff
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double totalTransmissionTime = 0.0;
    int successfulTransmissions = 0;

    for (int i = 0; i < m_numPackets * m_numUsers; ++i) {
        double backoffTime = dis(gen) * (1.0 / m_numUsers);
        double transmissionTime = backoffTime + m_transmissionTime;
        
        // Simulate transmission success probability
        if (dis(gen) < 0.8) {  // 80% success rate
            latencies.push_back(transmissionTime);
            totalTransmissionTime += transmissionTime;
            successfulTransmissions++;
        }
    }

    // Calculate throughput
    double packetSize = 1.0;  // KB
    m_throughput = (successfulTransmissions * packetSize * 8) / (totalTransmissionTime / 1000.0);
}

void WiFiStandard::simulateWiFi5Transmission(std::vector<double>& latencies) {
    // WiFi 5 - Multi-user MIMO, parallel transmission
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double totalTransmissionTime = 0.0;
    int successfulTransmissions = 0;

    // Channel state information exchange
    double initializationTime = m_numUsers * 0.2;  // 200 bytes per user

    for (int i = 0; i < m_numPackets; ++i) {
        double parallelTransmissionTime = m_transmissionTime;
        
        // Simulate round-robin scheduling
        for (int user = 0; user < m_numUsers; ++user) {
            double userTransmissionTime = parallelTransmissionTime / m_numUsers;
            
            if (dis(gen) < 0.9) {  // 90% success rate
                latencies.push_back(initializationTime + userTransmissionTime);
                successfulTransmissions++;
            }
        }

        totalTransmissionTime += initializationTime + parallelTransmissionTime;
    }

    // Calculate throughput
    double packetSize = 1.0;  // KB
    m_throughput = (successfulTransmissions * packetSize * 8) / (totalTransmissionTime / 1000.0);
}

void WiFiStandard::simulateWiFi6Transmission(std::vector<double>& latencies) {
    // WiFi 6 - OFDMA, sub-channel allocation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double totalTransmissionTime = 0.0;
    int successfulTransmissions = 0;

    // Sub-channel allocation options
    std::vector<int> subChannels = {2, 4, 10};  // MHz

    for (int i = 0; i < m_numPackets; ++i) {
        double channelAllocationTime = 0.5;  // 0.5 ms for allocation
        double parallelTransmissionTime = m_transmissionTime;

        // Simulate round-robin scheduling with sub-channel allocation
        for (int user = 0; user < m_numUsers; ++user) {
            int subChannelWidth = subChannels[user % subChannels.size()];
            double userTransmissionTime = parallelTransmissionTime / m_numUsers;
            
            if (dis(gen) < 0.95) {  // 95% success rate
                latencies.push_back(channelAllocationTime + userTransmissionTime);
                successfulTransmissions++;
            }
        }

        totalTransmissionTime += channelAllocationTime + parallelTransmissionTime;
    }

    // Calculate throughput
    double packetSize = 1.0;  // KB
    m_throughput = (successfulTransmissions * packetSize * 8) / (totalTransmissionTime / 1000.0);
}

double WiFiStandard::calculateAverageLatency(const std::vector<double>& latencies) {
    if (latencies.empty()) return 0.0;
    
    double totalLatency = 0.0;
    for (double latency : latencies) {
        totalLatency += latency;
    }
    return totalLatency / latencies.size();
}

// Getter methods
double WiFiStandard::getThroughput() const { return m_throughput; }
double WiFiStandard::getAverageLatency() const { return m_averageLatency; }
double WiFiStandard::getMaxLatency() const { return m_maxLatency; }