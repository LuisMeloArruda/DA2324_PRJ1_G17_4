#ifndef DA2324_PRJ1_G17_4_RESERVOIR_H
#define DA2324_PRJ1_G17_4_RESERVOIR_H

#include "Station.h"

class Reservoir: public Station {
private:
    string name;
    string municipality;
    unsigned long maxDelivery;
public:
    Reservoir(int id, string code, string name, string municipality, unsigned long maxDelivery = 0);
    string getName() const;
    void setName(string name);
    string getMunicipality() const;
    void setMunicipality(string municipality);
    unsigned long getMaxDelivery() const;
    void setMaxDelivery(unsigned long maxDelivery);
};

#endif //DA2324_PRJ1_G17_4_RESERVOIR_H
