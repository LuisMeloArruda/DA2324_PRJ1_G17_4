#include "Manager.h"

void Manager::readCSVs() {
    readReservoirs();
    readStations();
    readCities();
    readPipes();
}

void Manager::readReservoirs() {
    fstream file("../Project1DataSetSmall/Reservoirs_Madeira.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    getline(file, line); // Ignore header

    while (getline(file, line)) {
        // Exracting Info
        istringstream ss(line);
        int id;
        string code, name, municipality;
        unsigned long maxDelivery;
        getline(ss, name, ',');
        getline(ss, municipality, ',');
        ss >> id;
        ss.ignore(1);
        getline(ss, code, ',');
        ss >> maxDelivery;
        ss.ignore(1);

        Reservoir temp = Reservoir(id, code, name, municipality, maxDelivery);

        reservoirs.insert({id, &temp});
        g.addVertex(temp);
    }
}

void Manager::readStations() {
    fstream file("../Project1DataSetSmall/Stations_Madeira.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    getline(file, line); // Ignore header

    while (getline(file, line)) {
        istringstream ss(line);
        int id;
        string code;
        getline(ss, code, ',');
        ss >> id;
        ss.ignore(1);

        Station temp = Station(id, code);

        stations.insert({id, &temp});
        g.addVertex(temp);
    }

}

void Manager::readCities() {
    fstream file("../Project1DataSetSmall/Cities_Madeira.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    getline(file, line); // Ignore header

    while (getline(file, line)) {
        // Exracting Info
        istringstream ss(line);
        int id;
        string code, name;
        unsigned int demand, population;
        getline(ss, name, ',');
        ss >> id;
        ss.ignore(1);
        getline(ss, code, ',');
        ss >> demand;
        ss.ignore(1);
        ss >> population;
        ss.ignore(1);

        City temp = City(id, code, name, demand, population);

        cities.insert({id, &temp});
        g.addVertex(temp);
    }
}

void Manager::readPipes() {
    fstream file("../Project1DataSetSmall/Pipes_Madeira.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    getline(file, line); // Ignore header

    while (getline(file, line)) {
        // Extracting Info
        istringstream ss(line);
        string servicePointA, servicePointB;
        unsigned int capacity;
        bool direction;
        getline(ss, servicePointA, ',');
        getline(ss, servicePointB, ',');
        ss >> capacity;
        ss.ignore(1);
        ss >> direction;
        ss.ignore(1);

        Pipe temp = Pipe(servicePointA, servicePointB, capacity, direction);

        g.addBidirectionalEdge(Station(0, ))
    }
}
