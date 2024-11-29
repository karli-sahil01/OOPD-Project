#ifndef WIFI4_CSMA_CA_H
#define WIFI4_CSMA_CA_H

#include "access_point.h"
#include "user.h"
#include <vector>

class WiFi4 {
private:
    AccessPoint* ap;
    std::vector<User*> users;

public:
    WiFi4(AccessPoint* ap, std::vector<User*> users);
    void simulate();
    bool channelFree(); // Randomly checks if the channel is free
};

#endif // WIFI4_CSMA_CA_H
