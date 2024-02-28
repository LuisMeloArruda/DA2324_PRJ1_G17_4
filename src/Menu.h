#ifndef DA2324_PRJ1_G17_4_MENU_H
#define DA2324_PRJ1_G17_4_MENU_H

#include <iostream>

class Menu {
public:
    /**
     * @brief Menu (maybe to choose which dataset to use)
     * Complexity: O()
     */
    Menu();
    /**
     * @brief Main Menu
     * Complexity: O()
     */
    void mainMenu();
    /**
     * @brief Basic Service Metrics
     * Complexity: O()
     */
    void basicServiceMetrics();
    /**
     * @brief Reliability And Sensitivity
     * Complexity: O()
     */
    void reliabilityAndSensitivity();
    /**
     * @brief Allows choose between each or a specific city to
     * determine the maximum amount of water than can reach
     * Complexity: O()
     */
    void chooseEachSpecificCity();
};


#endif //DA2324_PRJ1_G17_4_MENU_H
