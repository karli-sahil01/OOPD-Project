#ifndef WIFI6_OFDMA_H
#define WIFI6_OFDMA_H

#include "frequency_channel.h"
#include "user.h"
#include <vector>

class WiFi6 {
private:
    FrequencyChannel* channel;
    std::vector<User*> users;

public:
    WiFi6(FrequencyChannel* channel, std::vector<User*> users);
    void simulate();
};

#endif // WIFI6_OFDMA_H
