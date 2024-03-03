#include "City.h"

City::City(int id, string code, string city, unsigned int demand, unsigned int population): Station(id, code) {
    this->city = city;
    this->demand = demand;
    this->population = population;
}

string City::getCity() const {
    return this->city;
}

void City::setCity(string city) {
    this->city = city;
}

unsigned int City::getDemand() const {
    return this->demand;
}

void City::setDemand(unsigned int demand) {
    this->demand = demand;
}

unsigned int City::getPopulation() const {
    return this->population;
}

void City::setPopulation(unsigned int population) {
    this->population = population;
}