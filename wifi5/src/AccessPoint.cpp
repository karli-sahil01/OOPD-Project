#include "AccessPoint.h"
#include <algorithm>
#include <random>

AccessPoint::AccessPoint(int channelWidth, std::string standard) 
    : m_channelWidth(channelWidth), 
      m_standard(standard), 
      m_channelOccupied(false),
      m_maxMIMOStreams(8),
      m_currentUserIndex(0) {}

bool AccessPoint::isChannelFree() const {
    return !m_channelOccupied;
}

void AccessPoint::allocateChannel(int users) {
    m_channelOccupied = true;

    if (m_standard == "WiFi5") {
        initializeMultiUserMIMO(users);
    } else if (m_standard == "WiFi6") {
        allocateOFDMASubChannels(users);
    }
}

void AccessPoint::releaseChannel() {
    m_channelOccupied = false;
    m_subChannelAllocations.clear();
}

void AccessPoint::initializeMultiUserMIMO(int users) {
    // Limit MIMO streams to either max streams or number of users
    m_maxMIMOStreams = std::min(m_maxMIMOStreams, users);
}

void AccessPoint::allocateOFDMASubChannels(int users) {
    // OFDMA sub-channel allocation (2, 4, 10 MHz)
    std::vector<int> subChannels = {2, 4, 10};
    
    m_subChannelAllocations.clear();
    for (int i = 0; i < users; ++i) {
        m_subChannelAllocations.push_back(subChannels[i % subChannels.size()]);
    }
}