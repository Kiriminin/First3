#pragma once
#include "Transport.h"

using namespace std;

class AirTransport : public Transport {
protected:
    double maxAltitude;

public:
    AirTransport(string n, double s, int c, double ma)
        : Transport(n, s, c), maxAltitude(ma) {}

    void Output() const {
        Transport::Output();
        cout << "Max Altitude: " << maxAltitude << endl;
    }
};

class Airplane : public AirTransport {
private:
    int numEngines;

public:
    Airplane(string n, double s, int c, double ma, int ne)
        : AirTransport(n, s, c, ma), numEngines(ne) {}

    void Output() const {
        AirTransport::Output();
        cout << "Number of Engines: " << numEngines << endl;
    }
};

class Helicopter : public AirTransport {
private:
    double rotorDiameter;

public:
    Helicopter(string n, double s, int c, double ma, double rd)
        : AirTransport(n, s, c, ma), rotorDiameter(rd) {}

    void Output() const {
        AirTransport::Output();
        cout << "Rotor Diameter: " << rotorDiameter << " meters" << endl;
    }
};

class Airship : public AirTransport {
private:
    double gasVolume;

public:
    Airship(string n, double s, int c, double ma, double gv)
        : AirTransport(n, s, c, ma), gasVolume(gv) {}

    void Output() const {
        AirTransport::Output();
        cout << "Gas Volume: " << gasVolume << " cubic meters" << endl;
    }
};
