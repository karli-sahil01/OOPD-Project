CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src
INCLUDE = include
BUILD = build

OBJS = $(SRC)/access_point.cpp $(SRC)/user.cpp $(SRC)/packet.cpp \
       $(SRC)/frequency_channel.cpp $(SRC)/wifi4_csma_ca.cpp \
       $(SRC)/wifi5_mu_mimo.cpp $(SRC)/wifi6_ofdma.cpp \
       $(SRC)/metrics.cpp $(SRC)/main.cpp  # Removed utilities.cpp here

TARGET = wifi_simulator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $(OBJS) -o $(TARGET)

clean:
	rm -f $(TARGET)
