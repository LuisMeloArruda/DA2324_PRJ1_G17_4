#include "Reservoir.h"

Reservoir::Reservoir(int id, string code, string name, string municipality, unsigned long maxDelivery): Station(id, code) {
    this->name = name;
    this->municipality = municipality;
    this->maxDelivery = maxDelivery;
}

string Reservoir::getName() const {
    return name;
}

void Reservoir::setName(string name) {
    this->name = name;
}

string Reservoir::getMunicipality() const {
    return this->municipality;
}

void Reservoir::setMunicipality(string municipality) {
    this->municipality = municipality;
}

unsigned long Reservoir::getMaxDelivery() const {
    return maxDelivery;
}

void Reservoir::setMaxDelivery(unsigned long maxDelivery) {
    this->maxDelivery = maxDelivery;
}