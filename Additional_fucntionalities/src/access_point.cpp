#include "access_point.h"
#include <iostream>

AccessPoint::AccessPoint(int id, double bandwidth, const std::string& modulation, double coding_rate)
    : id(id), bandwidth(bandwidth), modulation(modulation), coding_rate(coding_rate) {}

void AccessPoint::connectUser(User* user) {
    connected_users.push_back(user);
    std::cout << "User " << user->getId() << " connected to Access Point " << id << ".\n";
}

void AccessPoint::broadcast(Packet& packet) {
    std::cout << "Access Point " << id << " broadcasting packet of size " << packet.getSize() << " KB.\n";
    for (User* user : connected_users) {
        user->receiveData(packet);
    }
}

double AccessPoint::getBandwidth() const {
    return bandwidth;
}

void AccessPoint::allocateResources() {
    std::cout << "Allocating resources to users connected to Access Point " << id << ".\n";
}
