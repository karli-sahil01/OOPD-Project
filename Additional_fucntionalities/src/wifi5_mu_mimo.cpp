#include "wifi5_mu_mimo.h"
#include <iostream>

WiFi5::WiFi5(AccessPoint* ap, std::vector<User*> users) : ap(ap), users(users) {}

void WiFi5::simulate() {
    std::cout << "WiFi 5 Simulation: Collecting Channel State Information...\n";

    // Collect Channel State Information (CSI) from each user
    for (User* user : users) {
        // Create a CSI packet for each user
        Packet csiPacket(0.2, 0.01, "CSI"); // 200 bytes for CSI
        user->sendData(csiPacket); // Use user object to send the CSI packet
        std::cout << "User " << user->getId() << " sent a CSI packet." << std::endl;
    }

    std::cout << "CSI collected. Starting parallel communication...\n";

    // Send data packets to all users for parallel communication (simulating the broadcast process)
    for (int i = 0; i < 15; i++) { // Repeat for 15 ms
        for (User* user : users) {
            // Create a data packet for each user
            Packet dataPacket(1.0, 0.02, "data"); // 1 KB data packet
            ap->broadcast(dataPacket); // Broadcast the data packet to all users
            std::cout << "Access Point sent data packet to User " << user->getId() << std::endl;
        }
    }
}
