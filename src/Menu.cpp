#include "Menu.h"
#include <limits>

void Menu::mainMenu() {
    while (true) {
        std::cout << "\n\n\n"
                     "||-----------------------------||\n"
                     "||   Water Supply Management   ||\n"
                     "||-----------------------------||\n";
        std::cout << "\nChoose an option:\n"
                     "[1] Basic Service Metrics\n"
                     "[2] Reliability and Sensitivity to Failures\n"
                     "[3] Change Data Set\n"
                     "\n[0] Quit.\n"
                     "> ";
        int option;
        std::cin >> option;
        if (std::cin.fail()) {
            std::cout << "Invalid input\n"
                         "> ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mainMenu();
        } else {
            switch (option) {
                case 0:
                    exit(0);
                case 1:
                    basicServiceMetrics();
                    break;
                case 2:
                    reliabilityAndSensitivity();
                    break;
                case 3:
                    Menu();
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    mainMenu();
            }
        }
    }
}

void Menu::basicServiceMetrics() {
    std::cout << "\n\n"
                 "||-----------------------------||\n"
                 "||    Basic Service Metrics    ||\n"
                 "||-----------------------------||\n";
    std::cout << "\nChoose an option:\n"
                 "[1] Maximum amount of water than can reach to each or a specific city\n"
                 "[2] Check if existing network configuration meets water needs\n"
                 "[3] Balance load across the network\n"
                 "\n[0] Go back.\n"
                 "> ";
    int option;
    std::cin >> option;
    switch (option) {
        case 0:
            mainMenu();
            break;
        case 1:
            chooseEachSpecificCity();
            break;
        case 2:
            network.reservoirDeficit();
            break;
        case 3:
            network.initialMetrics();
            network.finalMetrics();
            break;
        default:
            std::cout << "Invalid option.\n";
            basicServiceMetrics();
    }
}

void Menu::chooseEachSpecificCity() {
    std::cout << "\nMaximum amount of water than can reach to...\n"
                 "[1] Each city\n"
                 "[2] Specific city\n"
                 "[3] Testing\n"
                 "\n[0] Go back.\n"
                 "> ";
    int option;
    std::cin >> option;
    std::string city;
    switch (option) {
        case 0:
            basicServiceMetrics();
            break;
        case 1:
            network.allCitiesMaximumFlow2();
            break;
        case 2:
            std::cout << "\nWhich city?"
                         "> ";
            std::cin >> city;
            network.maximumFlow(city);
            break;
        case 3:
            network.allCitiesMaximumFlow();
            break;
        default:
            std::cout << "Invalid option.\n";
            chooseEachSpecificCity();
    }
}

void Menu::reliabilityAndSensitivity() {
    std::cout << "\n\n"
                 "||-----------------------------||\n"
                 "|| Reliability and Sensitivity ||\n"
                 "||      to Failures Menu       ||\n"
                 "||-----------------------------||\n";
    std::cout << "\nChoose an option:\n"
                 "[1] Evaluate network's resiliency\n"
                 "[2] Temporarily remove pumping stations\n"
                 "[3] Determine pipeline failures in a specific city\n"
                 "[4] Determine Cities affected by a pipeline\n"
                 "\n[0] Go back.\n"
                 "> ";
    int option;
    string Code, pumpingCode;
    std::cin >> option;
    switch (option) {
        case 0:
            mainMenu();
            break;
        case 1:
            std::cout << "\nWhich reservoir?"
                         "> ";
            std::cin >> Code;
            network.affectedCitiesByReservoirs(Code);
            break;
        case 2:
            network.affectedCitiesByPumping();
            break;
        case 3:
            std::cout << "\nWhich city?"
                         "> ";
            std::cin >> Code;
            network.pipelinesFailures(Code);
            break;
        case 4:
            network.affectedCitiesByPipelines();
            break;
        default:
            std::cout << "Invalid option.\n";
            reliabilityAndSensitivity();
    }
}


Menu::Menu() {
    network = Manager();
    std::cout << "\n\n"
                 "||-----------------------------||\n"
                 "||    Which Data Set Do You    ||\n"
                 "||        Want To Use ?        ||\n"
                 "||-----------------------------||\n";
    std::cout << "\nChoose an option:\n"
                 "[1] Small Data Set - Madeira\n"
                 "[2] Large Data Set - Portugal\n"
                 "> ";
    int option;
    string cityCode, pumpingCode;
    std::cin >> option;
    switch (option) {
        case 1:
            network.initializeGraph(1);
            break;
        case 2:
            network.initializeGraph(2);
            break;
        default:
            std::cout << "Invalid option.\n";
            Menu();
    }
    mainMenu();
}
