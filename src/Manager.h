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
#include <cmath>

class Manager {
private:
    unordered_map<int, Reservoir> reservoirs;
    unordered_map<int, Station> stations;
    unordered_map<int, City> cities;
    unordered_map<int, Pipe> pipes;
    Graph<Station> g;
public:
    /**
     * @brief Reads data from CSV files and initializes the network.
     * @complexity O()
     */
    void initializeGraph();

    /**
     * @brief Reads reservoir data from a CSV file and populates the reservoirs map.
     * @complexity O()
     */
    void readReservoirs();

    /**
     * @brief Reads station data from a CSV file and populates the stations map.
     * @complexity O()
     */
    void readStations();

    /**
     * @brief Reads city data from a CSV file and populates the cities map.
     * @complexity O()
     */
    void readCities();

    /**
     * @brief Reads pipe data from a CSV file and populates the pipes map.
     * @complexity O()
     */
    void readPipes();

    /**
     * @brief
     * @complexity
     */
    void addArtificialSource();

    /**
     * @brief
     * @return
     */
    void addArtificialSink();

    /**
     * @brief
     * @param city
     * @complexity
     */
    void maximumFlow(string city);
    /**
     * @brief prints the maximum flow that reaches all cities
     */
    void allCitiesMaximumFlow();

    void allCitiesMaximumFlow2();

    void reservoirDeficit();

    void initialMetrics();

    int calculatePipeFlow(string a, string b);
};

#endif //DA2324_PRJ1_G17_4_MANAGER_H
