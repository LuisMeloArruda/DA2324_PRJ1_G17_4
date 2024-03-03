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
     * @complexity O()
     */
    void mainMenu();

    /**
     * @brief Displays Basic Service Metrics.
     * @complexity O()
     */
    void basicServiceMetrics();

    /**
     * @brief Displays Reliability And Sensitivity.
     * @complexity O()
     */
    void reliabilityAndSensitivity();

    /**
     * @brief Allows choose between each or a specific city to
     * determine the maximum amount of water than can reach
     * @complexity O()
     */
    void chooseEachSpecificCity();
private:
    Manager network;
};


#endif //DA2324_PRJ1_G17_4_MENU_H
