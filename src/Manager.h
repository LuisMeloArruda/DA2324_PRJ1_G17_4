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
     * @complexity O(n), where n is the number of reservoirs, stations, cities and pipes in the data set being read.
     */
    void initializeGraph(int i);

    /**
     * @brief Reads reservoir data from a CSV file and populates the reservoirs map.
     * @param i Chooses which data set to use.
     * @complexity O(R), where R is the number of reservoirs in the data set being read.
     */
    void readReservoirs(int i);

    /**
     * @brief Reads station data from a CSV file and populates the stations map.
     * @param i Chooses which data set to use.
     * @complexity O(S), where S is the number of stations in the data set being read.
     */
    void readStations(int i);

    /**
     * @brief Reads city data from a CSV file and populates the cities map.
     * @complexity O(C), where C is the number of cities in the data set being read.
     */
    void readCities(int i);

    /**
     * @brief Reads pipe data from a CSV file and populates the pipes map.
     * @param i Chooses which data set to use.
     * @complexity O(P), where P is the number of pipes in the data set being read.
     */
    void readPipes(int i);

    /**
     * @brief Adds an artificial source station to the graph.
     * @complexity O(R), where R is the number of reservoirs.
     */
    void addArtificialSource();

    /**
     * @brief Adds an artificial sink station to the graph.
     * @complexity O(C), where C is the number of cities.
     */
    void addArtificialSink();

    /**
     * @brief Computes the maximum flow for a given city using the Edmonds-Karp algorithm.
     * @param city Name of the city for which the maximum flow is calculated.
     * @complexity O(E^2 * V), where E is the number of edges and V is the number of vertices in the graph.
     */
    void maximumFlow(string city);

    /**
     * @brief Computes the maximum flow for all cities in the network using the Edmonds-Karp algorithm.
     * @complexity O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     */
    void allCitiesMaximumFlow();

    /**
     * @brief Computes the maximum flow for all cities in the network and prints the maximum flow of the network
     * and the flow into each city from the artificial sink station.
     * @complexity O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     */
    void allCitiesMaximumFlow2();

    /**
     * @brief Computes the deficit flow for each city in the network.
     * @complexity O(N * E), where N is the number of cities and E is the number of edges in the graph.
     */
    void reservoirDeficit();

    /**
     * @brief Computes initial metrics for the network before balancing.
     * Initial metrics, including average difference, variance, and maximum difference, are computed and printed.
     * @complexity O(P), where P is the number of pipes in the network.
     */
    void initialMetrics();

    /**
     * @brief Computes final metrics for the network after balancing.
     * Final metrics, including average difference, variance, and maximum difference, are computed and printed.
     * @complexity O(P), where P is the number of pipes in the network.
     */
    void finalMetrics();

    /**
     * @brief Identify the critical pipelines within a specific city
     * @param cityName
     * @complexity O(P * (V^2 + E)), where P is the number of pipelines, V is the number of vertices, and E is the number of edges in the graph.
     */
    void pipelinesFailures(string cityName);

    /**
     * @brief Computes the affected cities by a removed reservoir
     * @param reservoirCode
     * @complexity O(C * (V^2 + E)), where C is the number of cities, V is the number of vertices, and E is the number of edges in the graph.
     */
    void affectedCitiesByReservoirs(string reservoirCode);

    /**
     * @brief Computes the affected cities by a removed pipeline
     * @complexity O(P * (V^2 + E)), where P is the number of pipelines, V is the number of vertices, and E is the number of edges in the graph.
     */
    void affectedCitiesByPipelines();

    /**
     * @brief Computes the affected and non-affected cities by a removed pumping
     * @complexity O(P * (V^2 + E)), where P is the number of pumping stations, V is the number of vertices, and E is the number of edges in the graph.
     */
    void affectedCitiesByPumping();

    /**
     * @brief Set all incoming edges to zero and store in a vector
     * @param v ointer to the vertex whose incoming edges' capacities are to be stored.
     * @return The original capacities of the incoming edges of a vertex
     * @complexity O(K), where K is the number of incoming edges of the vertex.
     */
    vector<double> setZeroAndSaveCapacity(Vertex<Station>* v);

    /**
     * @brief Retrieve the flow rate of an edge between two stations.
     * @param a Code of the source station.
     * @param b Code of the destination station.
     * @return The flow rate of the edge between stations 'a' and 'b'.
     * @complexity O(1)
     */
    int calculatePipeFlow(string a, string b);

    /**
     * @brief Initiates the Edmonds-Karp algorithm to compute the maximum flow in the network.
     * @return The maximum flow in the network computed using the Edmonds-Karp algorithm.
     * @complexity O(V * E^2), where V is the number of vertices and E is the number of edges in the graph.
     */
    int initiateEdmondsKarp();

    /**
     * @brief
     * @complexity
     */
    void improvedAffectedCitiesByReservoirs();

    // gradient algorithm

    /**
     * @brief
     * @return
     * @complexity
     */
    double computeObjectiveFunction();

    /**
     * @brief
     * @complexity
     */
    void computeGradient();

    /**
     * @brief
     * @param learningRate
     * @complexity
     */
    void updateFlowValues(double learningRate);

    /**
     * @brief
     * @complexity
     */
    void gradientDescent();
};

#endif //DA2324_PRJ1_G17_4_MANAGER_H
