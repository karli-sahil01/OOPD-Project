# WiFi Simulator - OOPD Project

## Overview
This project simulates WiFi communication using three types of WiFi technologies: WiFi 4, WiFi 5, and WiFi 6. The goal is to model the transmission process and compute throughput, average latency, and maximum latency for various configurations of users and access points (APs). The simulator incorporates object-oriented features such as inheritance, data abstraction, data hiding, and polymorphism to model the behavior of access points and users.

## Project Structure

1. **WiFi 4 Communication**
   - Simulates the process of sniffing the channel and transmission attempts.
   - If the channel is free, data is transmitted; if not, a random backoff time is applied, followed by retransmission.
   - The simulation is conducted for three different configurations:
     - 1 user and 1 AP
     - 10 users and 1 AP
     - 100 users and 1 AP

2. **WiFi 5 Communication**
   - Introduces multi-user MIMO (MU-MIMO), enabling parallel communication.
   - A broadcast packet is sent by the AP, followed by each user sending their channel state information (CSI).
   - After CSI transmission, users can communicate in parallel for 15 ms, followed by the process repeating.
   - The simulation is done for the same three configurations as in WiFi 4.

3. **WiFi 6 Communication**
   - Implements OFDMA (Orthogonal Frequency Division Multiple Access), allowing the 20 MHz channel to be subdivided into smaller units (2 MHz, 4 MHz, or 10 MHz).
   - Each sub-channel can be used in parallel for 5 ms before the channel allocation is done again.
   - The simulation is conducted for the three configurations, similar to WiFi 4 and WiFi 5.

## Features
- **Throughput Calculation**: Measures the amount of data successfully transmitted per unit of time.
- **Latency Calculation**: Measures the time taken for a packet to be transmitted from the source to the destination.
- **Backoff Mechanism**: Models the random backoff time when the channel is busy (WiFi 4).
- **Round-Robin Scheduling**: Implements a round-robin scheduling for users (WiFi 5 and WiFi 6).
