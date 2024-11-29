#include "wifi6_ofdma.h"
#include <iostream>

WiFi6::WiFi6(FrequencyChannel* channel, std::vector<User*> users)
    : channel(channel), users(users) {}

void WiFi6::simulate() {
    std::cout << "WiFi 6 Simulation: Allocating subchannels...\n";

    for (size_t i = 0; i < users.size(); ++i) {
        if (channel->checkAvailability(i)) {
            channel->allocate(i);
            std::cout << "Subchannel " << i << " allocated to User " << users[i]->getId() << ".\n";
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (User* user : users) {
            Packet dataPacket(1.0, 0.02, "data");
            user->receiveData(dataPacket);
        }
    }

    std::cout << "Releasing subchannels...\n";
    for (size_t i = 0; i < users.size(); ++i) {
        channel->release(i);
    }
}
