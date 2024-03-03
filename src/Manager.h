#ifndef DA2324_PRJ1_G17_4_MANAGER_H
#define DA2324_PRJ1_G17_4_MANAGER_H

#include "Station.h"
#include "Graph.h"
#include "Reservoir.h"
#include "City.h"
#include "Pipe.h"

#include <unordered_map>
#include <sstream>
#include <iostream>
#include <fstream>

class Manager {
private:
    unordered_map<int, Reservoir*> reservoirs;
    unordered_map<int, Station*> stations;
    unordered_map<int, City*> cities;
    unordered_map<int, Pipe*> pipes;
    Graph<Station> g;
public:
    void readCSVs();
    void readReservoirs();
    void readStations();
    void readCities();
    void readPipes();
};
#endif //DA2324_PRJ1_G17_4_MANAGER_H
