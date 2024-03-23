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
     * @param i Chooses which data set to use.
     * @complexity O()
     */
    void initializeGraph(int i);

    /**
     * @brief Reads reservoir data from a CSV file and populates the reservoirs map.
     * @param i Chooses which data set to use.
     * @complexity O()
     */
    void readReservoirs(int i);

    /**
     * @brief Reads station data from a CSV file and populates the stations map.
     * @param i Chooses which data set to use.
     * @complexity O()
     */
    void readStations(int i);

    /**
     * @brief Reads city data from a CSV file and populates the cities map.
     * @complexity O()
     */
    void readCities(int i);

    /**
     * @brief Reads pipe data from a CSV file and populates the pipes map.
     * @param i Chooses which data set to use.
     * @complexity O()
     */
    void readPipes(int i);

    /**
     * @brief Adds an artificial source station to the graph.
     * @complexity O()
     */
    void addArtificialSource();

    /**
     * @brief Adds an artificial sink station to the graph.
     * @complexity O()
     */
    void addArtificialSink();

    /**
     * @brief Computes the maximum flow for a given city using the Edmonds-Karp algorithm.
     * @param city Name of the city for which the maximum flow is calculated.
     * @complexity O()
     */
    void maximumFlow(string city);

    /**
     * @brief Computes the maximum flow for all cities in the network using the Edmonds-Karp algorithm.
     * @complexity O()
     */
    void allCitiesMaximumFlow();

    /**
     * @brief Computes the maximum flow for all cities in the network and prints the maximum flow of the network
     * and the flow into each city from the artificial sink station.
     * @complexity O()
     */
    void allCitiesMaximumFlow2();

    /**
     * @brief Computes the deficit flow for each city in the network.
     * @complexity O()
     */
    void reservoirDeficit();

    /**
     * @brief Computes initial metrics for the network before balancing.
     * Initial metrics, including average difference, variance, and maximum difference, are computed and printed.
     * @complexity O()
     */
    void initialMetrics();

    /**
     * @brief
     * @param cityName
     * @complexity
     */
    void pipelinesFailures(string cityName);

    void affectedCitiesByReservoirs(string reservoirCode);

    void affectedCitiesByPipelines();

    void affectedCitiesByPumping();

    vector<double> setZeroAndSaveCapacity(Vertex<Station>* v);

    /*Auxiliar*/

    /**
     * @brief
     * @param a
     * @param b
     * @return
     * @complexity
     */
    int calculatePipeFlow(string a, string b);

    /**
     * @brief Initiates the Edmonds-Karp algorithm to compute the maximum flow in the network.
     * @return The maximum flow in the network computed using the Edmonds-Karp algorithm.
     * @complexity O()
     */
    int initiateEdmondsKarp();
};

#endif //DA2324_PRJ1_G17_4_MANAGER_H
