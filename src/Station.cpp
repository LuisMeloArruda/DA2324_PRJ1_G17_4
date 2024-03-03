#include "Station.h"

int Station::getId() const {
    return this->id;
}

void Station::setId(int id) {
    this->id = id;
}

string Station::getCode() const {
    return this->code;
}

void Station::setCode(string code) {
    this->code = code;
}

Station::Station(int id, string code) {
    this->id = id;
    this->code = code;
}

bool Station::operator==(const Station &secondStation) const{
    return code==secondStation.code;
}