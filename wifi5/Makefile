# Variables
CXX = g++
AR = ar
CXXFLAGS = -c -std=c++11 -I./include -Wall
LDFLAGS = -L.

# Object files
OBJS = WiFiStandard.o AccessPoint.o User.o Packet.o

# Target executable
main: libwifi_simulation.a main.o
	$(CXX) -o main main.o -L. -lwifi_simulation

# Create static library
libwifi_simulation.a: $(OBJS)
	$(AR) rcs libwifi_simulation.a $(OBJS)

# Compilation rules for individual source files
WiFiStandard.o: src/WiFiStandard.cpp include/WiFiStandard.h
	$(CXX) $(CXXFLAGS) src/WiFiStandard.cpp -o WiFiStandard.o

AccessPoint.o: src/AccessPoint.cpp include/AccessPoint.h
	$(CXX) $(CXXFLAGS) src/AccessPoint.cpp -o AccessPoint.o

User.o: src/User.cpp include/User.h
	$(CXX) $(CXXFLAGS) src/User.cpp -o User.o

Packet.o: src/Packet.cpp include/Packet.h
	$(CXX) $(CXXFLAGS) src/Packet.cpp -o Packet.o

main.o: src/main.cpp include/WiFiStandard.h
	$(CXX) $(CXXFLAGS) src/main.cpp -o main.o

# Clean up generated files
clean:
	rm -f *.o *.a main