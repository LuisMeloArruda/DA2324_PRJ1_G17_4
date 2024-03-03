#ifndef DA2324_PRJ1_G17_4_CITY_H
#define DA2324_PRJ1_G17_4_CITY_H

#include "Station.h"

class City: public Station {
private:
    string city;
    unsigned int demand;
    unsigned int population;
public:
    City(int id, string code, string city, unsigned int demand, unsigned int population);
    string getCity() const;
    void setCity(string city);
    unsigned int getDemand() const;
    void setDemand(unsigned int demand);
    unsigned int getPopulation() const;
    void setPopulation(unsigned int population);
};

#endif //DA2324_PRJ1_G17_4_CITY_H
