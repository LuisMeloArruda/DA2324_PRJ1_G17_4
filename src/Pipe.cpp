#include "Pipe.h"

Pipe::Pipe(string servicePointA, string servicePointB, unsigned int capacity, bool direction) {
    this->servicePointA = servicePointA;
    this->servicePointB = servicePointB;
    this->capacity = capacity;
    this->direction = direction;
}

string Pipe::getServicePointA() const {
    return this->servicePointA;
}

void Pipe::setServicePointA(string servicePointA) {
    this->servicePointA = servicePointA;
}

string Pipe::getServicePointB() const {
    return this->servicePointB;
}

void Pipe::setServicePointB(string servicePointB) {
    this->servicePointB = servicePointB;
}

unsigned int Pipe::getCapacity() const {
    return this->capacity;
}

void Pipe::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

bool Pipe::getDirection() const {
    return this->direction;
}

void Pipe::setDirection(bool direction) {
    this->direction = direction;
}