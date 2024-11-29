#include "wifi4_csma_ca.h"
#include <iostream>
#include <cstdlib> // For random backoff
#include <ctime>   // For seeding random number generator

WiFi4::WiFi4(AccessPoint* ap, std::vector<User*> users) : ap(ap), users(users) {
    std::srand(std::time(nullptr)); // Seed random number generator
}

void WiFi4::simulate() {
    for (User* user : users) {
        Packet packet(1.0, std::rand() % 1000 / 1000.0, "data"); // 1 KB packet
        int attempts = 0;
        while (true) {
            if (channelFree()) {
                ap->broadcast(packet);
                break;
            } else {
                int backoff = std::rand() % 10 + 1; // Random backoff time
                std::cout << "User " << user->getId() << " deferring transmission by " << backoff << " ms.\n";
                attempts++;
            }
            if (attempts > 5) {
                std::cout << "User " << user->getId() << " failed to transmit after multiple attempts.\n";
                break;
            }
        }
    }
}

bool WiFi4::channelFree() {
    return std::rand() % 2 == 0; // Randomly decide if channel is free
}
