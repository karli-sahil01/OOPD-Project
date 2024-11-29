#ifndef ACCESS_POINT_H
#define ACCESS_POINT_H

#include <vector>
#include <string>

class AccessPoint {
public:
    // Constructor
    AccessPoint(int channelWidth, std::string standard);

    // Channel management methods
    bool isChannelFree() const;
    void allocateChannel(int users);
    void releaseChannel();

    // MIMO and OFDMA specific methods
    void initializeMultiUserMIMO(int users);
    void allocateOFDMASubChannels(int users);

private:
    // Channel characteristics
    int m_channelWidth;  // MHz
    std::string m_standard;
    bool m_channelOccupied;

    // MIMO and OFDMA specific attributes
    int m_maxMIMOStreams;
    std::vector<int> m_subChannelAllocations;

    // Scheduling attributes
    int m_currentUserIndex;
};

#endif // ACCESS_POINT_H