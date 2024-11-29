#ifndef USER_H
#define USER_H

#include <queue>
#include "packet.h"

class User {
private:
    int id;
    std::queue<Packet> buffer;

public:
    User(int id);

    int getId() const;
    void sendData(Packet& packet);
    void receiveData(const Packet& packet);
    bool hasPendingPackets() const;
};

#endif // USER_H
