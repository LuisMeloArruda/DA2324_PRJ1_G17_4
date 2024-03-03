#ifndef DA2324_PRJ1_G17_4_RESERVOIR_H
#define DA2324_PRJ1_G17_4_RESERVOIR_H

#include "Station.h"

class Reservoir: public Station {
private:
    string name;
    string municipality;
    unsigned long maxDelivery;
public:
    /**
     * @brief Constructor for the Reservoir class.
     * @param id The ID of the reservoir.
     * @param code The code of the reservoir.
     * @param name The name of the reservoir.
     * @param municipality The municipality where the reservoir is located.
     * @param maxDelivery The maximum delivery of the reservoir (default = 0).
     */
    Reservoir(int id, string code, string name, string municipality, unsigned long maxDelivery = 0);

    /**
     * @brief Get the name of the reservoir.
     * @return The name of the reservoir.
     */
    string getName() const;

    /**
     * @brief Set the name of the reservoir.
     * @param name The name of the reservoir.
     */
    void setName(string name);

    /**
     * @brief Get the municipality where the reservoir is located.
     * @return The municipality where the reservoir is located.
     */
    string getMunicipality() const;

    /**
     * @brief Set the municipality where the reservoir is located.
     * @param municipality The municipality where the reservoir is located.
     */
    void setMunicipality(string municipality);

    /**
     * @brief Get the maximum delivery of the reservoir.
     * @return The maximum delivery of the reservoir.
     */
    unsigned long getMaxDelivery() const;

    /**
     * @brief Set the maximum delivery of the reservoir.
     * @param maxDelivery The maximum delivery of the reservoir.
     */
    void setMaxDelivery(unsigned long maxDelivery);
};

#endif //DA2324_PRJ1_G17_4_RESERVOIR_H
