
#ifndef DA2324_PRJ1_G17_4_PIPE_H
#define DA2324_PRJ1_G17_4_PIPE_H

#include <string>
using namespace std;

class Pipe {
private:
    string servicePointA;
    string servicePointB;
    unsigned int capacity;
    bool direction;
public:
    Pipe(string servicePointA, string servicePointB, unsigned int capacity, bool direction);
    string getServicePointA() const;
    void setServicePointA(string servicePointA);
    string getServicePointB() const;
    void setServicePointB(string servicePointB);
    unsigned int getCapacity() const;
    void setCapacity(unsigned int capacity);
    bool getDirection() const;
    void setDirection(bool direction);
};
#endif //DA2324_PRJ1_G17_4_PIPE_H
