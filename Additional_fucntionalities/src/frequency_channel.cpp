#include "frequency_channel.h"

FrequencyChannel::FrequencyChannel(double bandwidth, int num_subchannels)
    : bandwidth(bandwidth), subchannels(num_subchannels, true) {}

bool FrequencyChannel::checkAvailability(int subchannel) const {
    return subchannels[subchannel];
}

void FrequencyChannel::allocate(int subchannel) {
    subchannels[subchannel] = false;
}

void FrequencyChannel::release(int subchannel) {
    subchannels[subchannel] = true;
}

double FrequencyChannel::getBandwidth() const {
    return bandwidth;
}
