#ifndef DA2324_PRJ1_G17_4_STATION_H
#define DA2324_PRJ1_G17_4_STATION_H

#include <string>

using namespace std;

class Station {
private:
    int id;
    string code;
public:
    /**
     * @brief Constructor for the Station class.
     * @param id The id of the station.
     * @param code The code of the station.
     */
     Station(int id, string code);

    /**
     * @brief Get the ID of the station.
     * @return The ID of the station.
     */
    int getId() const;

    /**
     * @brief Set the ID of the station.
     * @param id The ID of the station.
     */
    void setId(int Id);

    /**
    * @brief Get the code of the station.
    * @return The code of the station.
    */
    string getCode() const;

    /**
     * @brief Set the code of the station.
     * @param code The code of the station.
     */
    void setCode(string code);

    /**
     * @brief Equality operator for comparing two stations.
     * @param secondStation The second station to compare with.
     * @return True if both stations have the same code, otherwise false.
     * @complexity O(1)
     */
    bool operator==(const Station &secondStation) const;
};

#endif //DA2324_PRJ1_G17_4_STATION_H