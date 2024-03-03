#ifndef DA2324_PRJ1_G17_4_RESERVOIR_H
#define DA2324_PRJ1_G17_4_RESERVOIR_H

#include "Station.h"

class Reservoir: public Station {
private:
    string name;
    string municipality;
    unsigned long maxDelivery;
public:
    Reservoir(string name, string municipality, int id, string code, unsigned long maxDelivery);
    string getName() const;
    void setName(string name);
    string getName() const;
    void setName(string name);
};

#endif //DA2324_PRJ1_G17_4_RESERVOIR_H
