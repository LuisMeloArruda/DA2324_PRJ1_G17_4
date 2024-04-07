#ifndef DA2324_PRJ1_G17_4_MENU_H
#define DA2324_PRJ1_G17_4_MENU_H

#include "Manager.h"

#include <iostream>

class Menu {
public:
    /**
     * @brief Constructor for the Menu class.
     */
    Menu();

    /**
     * @brief Displays the Main Menu options.
     *
     * Complexity: O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     *
     */
    void mainMenu();

    /**
     * @brief Displays Basic Service Metrics.
     *
     * Complexity: O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     *
     */
    void basicServiceMetrics();

    /**
     * @brief Displays Reliability And Sensitivity.
     *
     * Complexity:  O(N * (V^2 + E)), where N is the number of cities, V is the number of vertices, and E is the number of edges in the graph.
     *
     */
    void reliabilityAndSensitivity();

    /**
     * @brief Allows choose between each or a specific city to determine the maximum amount of water than can reach
     *
     * Complexity: O(N * E^2 * V), where N is the number of cities, E is the number of edges, and V is the number of vertices in the graph.
     *
     */
    void chooseEachSpecificCity();
private:
    Manager network;
};


#endif //DA2324_PRJ1_G17_4_MENU_H
