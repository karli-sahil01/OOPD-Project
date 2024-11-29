#ifndef ACCESS_POINT_H
#define ACCESS_POINT_H

#include <vector>
#include <string>
#include "user.h"
#include "packet.h"

class AccessPoint {
private:
    int id;
    double bandwidth;
    std::string modulation;
    double coding_rate;
    std::vector<User*> connected_users;

public:
    AccessPoint(int id, double bandwidth, const std::string& modulation, double coding_rate);

    void connectUser(User* user);
    void broadcast(Packet& packet);
    double getBandwidth() const;
    void allocateResources();
};

#endif // ACCESS_POINT_H
