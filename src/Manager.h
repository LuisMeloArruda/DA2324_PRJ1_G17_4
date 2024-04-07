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
     *
     * Complexity: O(n), where n is the number of reservoirs, stations, cities and pipes in the data set being read.
     *
     * @param i Chooses which data set to use.
     */
    void initializeGraph(int i);

    /**
     * @brief Reads reservoir data from a CSV file and populates the reservoirs map.
     *
     * Complexity: O(R), where R is the number of reservoirs in the data set being read.
     *
     * @param i Chooses which data set to use.
     */
    void readReservoirs(int i);

    /**
     * @brief Reads station data from a CSV file and populates the stations map.
     *
     * Complexity: O(S), where S is the number of stations in the data set being read.
     *
     * @param i Chooses which data set to use.
     */
    void readStations(int i);

    /**
     * @brief Reads city data from a CSV file and populates the cities map.
     *
     * Complexity: O(C), where C is the number of cities in the data set being read.
     *
     */
    void readCities(int i);

    /**
     * @brief Reads pipe data from a CSV file and populates the pipes map.
     *
     * Complexity: O(P), where P is the number of pipes in the data set being read.
     *
     * @param i Chooses which data set to use.
     */
    void readPipes(int i);

    /**
     * @brief Adds an artificial source station to the graph.
     *
     * Complexity: O(R), where R is the number of reservoirs.
     *
     */
    void addArtificialSource();

    /**
     * @brief Adds an artificial sink station to the graph.
     *
     * Complexity: O(C), where C is the number of cities.
     *
     */
    void addArtificialSink();

    /**
     * @brief Computes the maximum flow for a given city using the Edmonds-Karp algorithm.
     *
     * Complexity: O(E^2 * V), where E is the number of edges and V is the number of vertices in the graph.
     *
     * @param city Name of the city for which the maximum flow is calculated.
     */
    void maximumFlow(string city);

    /**
     * @brief Computes the maximum flow for all cities in the network and prints the maximum flow of the network
     * and the flow into each city from the artificial sink station.
     *
     * Complexity: O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     *
     */
    void allCitiesMaximumFlow();

    /**
     * @brief Computes the deficit flow for each city in the network.
     *
     * Complexity: O(N * E), where N is the number of cities and E is the number of edges in the graph.
     *
     */
    void reservoirDeficit();

    /**
     * @brief Computes various metrics related to edge flow and weight differences.
     * It computes the average difference, variance, and the maximum difference.
     *
     * Complexity: O(V + E), V is the number of vertices and E is the number of edges in the graph.
     *
     * @return A vector containing three metrics: average difference, variance, and maximum difference.
     */
    vector<double> computeMetrics();

    /**
     * @brief Computes initial metrics for the network before balancing.
     * Initial metrics, including average difference, variance, and maximum difference, are computed and printed.
     *
     * Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges in the graph.
     *
     */
    void initialMetrics();

    /**
     * @brief Computes final metrics for the network after balancing.
     * Final metrics, including average difference, variance, and maximum difference, are computed and printed.
     *
     * Complexity: O(N * E), where N is the number of vertices and E is the number of edges in the graph.
     *
     */
    void finalMetrics();

    /**
     * @brief Identify the critical pipelines within a specific city
     *
     * Complexity: O(P * (V^2 + E)), where P is the number of pipelines, V is the number of vertices and E is the number of edges in the graph.
     *
     * @param cityName
     */
    void pipelinesFailures(string cityName);

    /**
     * @brief Computes the affected cities by a removed reservoir
     *
     * Complexity: O(C * (V^2 + E)), where C is the number of cities, V is the number of vertices, and E is the number of edges in the graph.
     *
     * @param reservoirCode
     */
    void affectedCitiesByReservoirs(string reservoirCode);

    /**
     * @brief Computes the affected cities by a removed pipeline
     *
     * Complexity: O(P * (V^2 + E)), where P is the number of pipelines, V is the number of vertices, and E is the number of edges in the graph.
     *
     */
    void affectedCitiesByPipelines();

    /**
     * @brief Computes the affected and non-affected cities by a removed pumping
     *
     * Complexity: O(P * (V^2 + E)), where P is the number of pumping stations, V is the number of vertices, and E is the number of edges in the graph.
     *
     */
    void affectedCitiesByPumping();

    /**
     * @brief This function removes pipes from the graph and prints out the affected cities.
     * If any of the pipes are invalid the function doesn't do anything and prints out an error.
     *
     * Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges in the graph.
     *
     * @param pipes Pipes to be removed
     */
    void simulation(vector<pair<string, string>> pipes);

    /**
     * @brief Set all incoming edges to zero and store in a vector
     *
     * Complexity: O(K), where K is the number of incoming edges of the vertex.
     *
     * @param v pointer to the vertex whose incoming edges' capacities are to be stored.
     * @return The original capacities of the incoming edges of a vertex
     */
    vector<double> setZeroAndSaveCapacity(Vertex<Station>* v);

    /**
     * @brief Initiates the Edmonds-Karp algorithm to compute the maximum flow in the network.
     *
     * Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges in the graph.
     *
     * @return The maximum flow in the network computed using the Edmonds-Karp algorithm.
     */
    int initiateEdmondsKarp();
};

#endif //DA2324_PRJ1_G17_4_MANAGER_H
