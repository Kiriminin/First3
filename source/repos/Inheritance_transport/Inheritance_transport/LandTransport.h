#pragma once
#include "Transport.h"

using namespace std;

class LandTransport : public Transport {
protected:
    int wheels;
    string terrainType;

public:
    LandTransport(string n, double s, int c, int w, string tt)
        : Transport(n, s, c), wheels(w), terrainType(tt) {}

    void Output() const {
        Transport::Output();
        cout << "Wheels: " << wheels << "\nTerrain Type: " << terrainType << endl;
    }
};

class Car : public LandTransport {
private:
    string engineType;

public:
    Car(string n, double s, int c, int w, string tt, string et)
        : LandTransport(n, s, c, w, tt), engineType(et) {}

    void Output() const {
        LandTransport::Output();
        cout << "Engine Type: " << engineType << endl;
    }
};

class HorseDrawn : public LandTransport {
private:
    string animalType;

public:
    HorseDrawn(string n, double s, int c, int w, string tt, string at)
        : LandTransport(n, s, c, w, tt), animalType(at) {}

    void Output() const {
        LandTransport::Output();
        cout << "Animal Type: " << animalType << endl;
    }
};

class Railway : public LandTransport {
private:
    int numWagon;

public:
    Railway(string n, double s, int c, int w, string tt, int nw)
        : LandTransport(n, s, c, w, tt), numWagon(nw) {}

    void Output() const {
        LandTransport::Output();
        cout << "Number of Wagons: " << numWagon << endl;
    }
};
