#pragma once
#include "Transport.h"

using namespace std;

class WaterTransport : public Transport {
protected:
    double displacement;
    double payload;

public:
    WaterTransport(string n, double s, int c, double d, double p)
        : Transport(n, s, c), displacement(d), payload(p) {}

    void Output() const {
        Transport::Output();
        cout << "Displacement: " << displacement << "\nPayload: " << payload << endl;
    }
};

class SteamBoat : public WaterTransport {
private:
    string fuelType;

public:
    SteamBoat(string n, double s, int c, double d, double p, string ft)
        : WaterTransport(n, s, c, d, p), fuelType(ft) {}

    void Output() const {
        WaterTransport::Output();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Boat : public WaterTransport {
private:
    string material;

public:
    Boat(string n, double s, int c, double d, double p, string m)
        : WaterTransport(n, s, c, d, p), material(m) {}

    void Output() const {
        WaterTransport::Output();
        cout << "Material: " << material << endl;
    }
};

class Tanker : public WaterTransport {
private:
    int numContainers;

public:
    Tanker(string n, double s, int c, double d, double p, int nc)
        : WaterTransport(n, s, c, d, p), numContainers(nc) {}

    void Output() const {
        WaterTransport::Output();
        cout << "Number of Containers: " << numContainers << endl;
    }
};