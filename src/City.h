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
     * @param id
     * @param code
     * @param city
     * @param demand
     * @param population
     */
    City(int id, string code, string city, double demand, unsigned int population);

    /**
     *
     * @return
     */
    string getCity() const;

    /**
     *
     * @param city
     */
    void setCity(string city);

    /**
     *
     * @return
     */
    unsigned int getDemand() const;

    /**
     *
     * @param demand
     */
    void setDemand(unsigned int demand);

    /**
     *
     * @return
     */
    unsigned int getPopulation() const;

    /**
     *
     * @param population
     */
    void setPopulation(unsigned int population);
};

#endif //DA2324_PRJ1_G17_4_CITY_H
