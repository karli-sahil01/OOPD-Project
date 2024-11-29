#ifndef WIFI5_MU_MIMO_H
#define WIFI5_MU_MIMO_H

#include "access_point.h"
#include "user.h"
#include <vector>

class WiFi5 {
private:
    AccessPoint* ap;
    std::vector<User*> users;

public:
    WiFi5(AccessPoint* ap, std::vector<User*> users);
    void simulate();
};

#endif // WIFI5_MU_MIMO_H
