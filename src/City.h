#ifndef DA2324_PRJ1_G17_4_CITY_H
#define DA2324_PRJ1_G17_4_CITY_H

#include "Station.h"

class City: public Station {
private:
    string city;
    double demand;
    unsigned int population;
public:
    /**
     * @brief Constructor for the City class.
     * @param id The ID of the city.
     * @param code The code of the city.
     * @param city The name of the city.
     * @param demand The demand of the city.
     * @param population The population of the city.
     */
    City(int id, string code, string city, double demand, unsigned int population);

    /**
     * @brief Gets the name of the city.
     * @return The name of the city.
     */
    string getCity() const;

    /**
     * @brief Sets the name of the city.
     * @param city The name of the city.
     */
    void setCity(string city);

    /**
     * @brief Gets the demand of the city.
     * @return The demand of the city.
     */
    unsigned int getDemand() const;

    /**
     * @brief Sets the demand of the city.
     * @param demand The demand of the city.
     */
    void setDemand(unsigned int demand);

    /**
     * @brief Gets the population of the city.
     * @return The population of the city.
     */
    unsigned int getPopulation() const;

    /**
     * @brief Sets the population of the city.
     * @param population The population of the city.
     */
    void setPopulation(unsigned int population);
};

#endif //DA2324_PRJ1_G17_4_CITY_H
