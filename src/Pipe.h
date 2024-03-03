
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
    /**
     * @brief Constructor for the Pipe class.
     * @param servicePointA The code of service point A connected by the pipe.
     * @param servicePointB The code of service point B connected by the pipe.
     * @param capacity Maximum capacity of the pipe.
     * @param direction Direction of the pipe (true for unidirectional, false for bidirectional).
     */
    Pipe(string servicePointA, string servicePointB, unsigned int capacity, bool direction);

    /**
     * @brief Get the code of service point A connected by the pipe.
     * @return The code of the service point A connected by the pipe.
     */
    string getServicePointA() const;

    /**
     * @brief Set the code of service point A connected by the pipe.
     * @param servicePointA The code of service point A connected by the pipe.
     */
    void setServicePointA(string servicePointA);

    /**
     * @brief Get the code of the first service point B connected by the pipe.
     * @return The code of the first service point B connected by the pipe.
     */
    string getServicePointB() const;

    /**
     * @brief Set the code of service point B connected by the pipe.
     * @param servicePointA The code of service point B connected by the pipe.
     */
    void setServicePointB(string servicePointB);

    /**
     * @brief Get the maximum capacity of the pipe.
     * @return The maximum capacity of the pipe.
     */
    unsigned int getCapacity() const;

    /**
     * @brief Set the maximum capacity of the pipe.
     * @param capacity The maximum capacity of the pipe.
     */
    void setCapacity(unsigned int capacity);

    /**
     * @brief Get the direction of the pipe.
     * @return The direction of the pipe (true for unidirectional, false for bidirectional).
     */
    bool getDirection() const;

    /**
     * @brief Set the direction of the pipe.
     * @return The direction of the pipe (true for unidirectional, false for bidirectional).
     */
    void setDirection(bool direction);

    /**
     * @brief Equality operator for comparing two pioes.
     * @param secondPipe The second pipr to compare with.
     * @return True if both pipes have the same service points, otherwise false.
     * @complexity O(1)
     */
    bool operator==(const Pipe &secondPipe) const;
};

#endif //DA2324_PRJ1_G17_4_PIPE_H
