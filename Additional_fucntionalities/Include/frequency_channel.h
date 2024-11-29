#ifndef FREQUENCY_CHANNEL_H
#define FREQUENCY_CHANNEL_H

#include <vector>

class FrequencyChannel {
private:
    double bandwidth;
    std::vector<bool> subchannels;  // Availability of subchannels

public:
    FrequencyChannel(double bandwidth, int num_subchannels);

    bool checkAvailability(int subchannel) const;
    void allocate(int subchannel);
    void release(int subchannel);
    double getBandwidth() const;
};

#endif // FREQUENCY_CHANNEL_H
