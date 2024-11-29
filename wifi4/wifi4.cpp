#include "wifi4.h"
#include <iostream>
#include <random>
#include <cmath>

const double BACKOFF_LIMIT = 50;         // Maximum backoff in microseconds

// FrequencyChannel class constructor
FrequencyChannel::FrequencyChannel(double bandwidth, int modulation, double codingRate)
    : bandwidth(bandwidth), modulation(modulation), codingRate(codingRate) {}

// Calculate the data rate for the frequency channel
double FrequencyChannel::getDataRate() const {
    return bandwidth * codingRate * log2(modulation);
}

// Calculate the transmission time for a packet
double FrequencyChannel::getTransmissionTime() const {
    return Packet::SIZE_BITS / getDataRate() * 1e6; // μs
}

// User class constructor
User::User(FrequencyChannel &channel) : channel(channel), backoffTime(0), latency(0) {}

// Generate a random backoff time for a user based on the number of users
double User::generateBackoff(int numUsers) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    double scaledBackoffLimit = BACKOFF_LIMIT * (1 + (numUsers - 1) * 0.1);
    std::uniform_real_distribution<double> dist(0, scaledBackoffLimit);
    return dist(rng);
}

// Simulate the transmission process for a user
void User::transmit(int numUsers) {
    if (numUsers > 1) {
        backoffTime = generateBackoff(numUsers);
    } else {
        backoffTime = 0;
    }

    double transmissionTime = channel.getTransmissionTime();
    latency = transmissionTime + backoffTime;
}

// Get the backoff time for the user
double User::getBackoffTime() const {
    return backoffTime;
}

// Get the latency for the user
double User::getLatency() const {
    return latency;
}

// AccessPoint class constructor
AccessPoint::AccessPoint(double bandwidth, int modulation, double codingRate)
    : channel(bandwidth, modulation, codingRate) {}

// Simulate the network for the given number of users
void AccessPoint::simulate(int numUsers) {
    users.clear();
    for (int i = 0; i < numUsers; ++i) {
        users.emplace_back(channel);
    }

    double totalBackoff = 0;
    double totalTime = 0;
    double maxLatency = 0;

    for (auto &user : users) {
        user.transmit(numUsers);
        totalBackoff += user.getBackoffTime();
        totalTime += user.getLatency();
        maxLatency = std::max(maxLatency, user.getLatency());
    }

    double throughput = (numUsers * Packet::SIZE_BITS) / (totalTime * 1e-6);
    throughput *= 1e-6; // Convert to Mbps
    double averageLatency = totalTime / numUsers;

    std::cout << "Number of Users: " << numUsers << std::endl;
    std::cout << "Throughput: " << throughput << " Mbps" << std::endl;
    std::cout << "Average Latency: " << averageLatency << " microseconds" << std::endl;
    std::cout << "Maximum Latency: " << maxLatency << " microseconds" << std::endl;
}
