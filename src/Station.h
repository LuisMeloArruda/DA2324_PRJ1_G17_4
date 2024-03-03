#ifndef DA2324_PRJ1_G17_4_STATION_H
#define DA2324_PRJ1_G17_4_STATION_H

#include <string>

using namespace std;

class Station {
private:
    int id;
    string code;
public:
    Station(int id, string code);
    int getId() const;
    void setId(int Id);
    string getCode() const;
    void setCode(string code);
    bool operator==(const Station &secondStation) const;
};

#endif //DA2324_PRJ1_G17_4_STATION_H