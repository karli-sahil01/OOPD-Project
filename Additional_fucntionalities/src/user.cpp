#include "user.h"
#include <iostream>

User::User(int id) : id(id) {}

int User::getId() const {
    return id;
}

void User::sendData(Packet& packet) {
    std::cout << "User " << id << " is sending a packet of size " << packet.getSize() << " KB.\n";
}

void User::receiveData(const Packet& packet) {
    buffer.push(packet);
    std::cout << "User " << id << " received a packet of size " << packet.getSize() << " KB.\n";
}

bool User::hasPendingPackets() const {
    return !buffer.empty();
}
