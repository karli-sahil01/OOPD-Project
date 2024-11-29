#include <iostream>
#include "wifi4.h"

int main() {
    int numUsers;
    std::cout << "Enter the number of users: ";
    std::cin >> numUsers;

    // Initialize Access Point with 20 MHz bandwidth, 256-QAM modulation, and 5/6 coding rate
    AccessPoint ap(20e6, 256, 5.0 / 6.0);

    // Simulate the network with the given number of users
    ap.simulate(numUsers);

    return 0;
}