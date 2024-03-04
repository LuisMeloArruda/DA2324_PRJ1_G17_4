#include "Manager.h"

void Manager::initializeGraph() {
    readReservoirs();
    readStations();
    readCities();
    readPipes();
    addArtificialSource();
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

        reservoirs.insert({id, temp});
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
        ss >> id;
        ss.ignore(1);
        getline(ss, code, ',');
        Station temp = Station(id, code);

        stations.insert({id, temp});
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
        char comma;
        unsigned int population;
        double demand;
        getline(ss, name, ',');
        ss >> id;
        ss.ignore(1);
        getline(ss, code, ',');
        ss >> demand;
        ss.ignore(1);
        ss.ignore(1);
        ss >> population;
        ss >> comma;
        while (comma == ',') {
            unsigned int temp = population * 1000;
            ss >> population;
            population += temp;
            ss >> comma;
        }

        City temp = City(id, code, name, demand, population);

        cities.insert({id, temp});
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

        if (direction) {
            if (!g.addBidirectionalEdge(Station(0, servicePointA), Station(0, servicePointB), capacity)) cout << "BIDIRECTION ERROR" << endl;
        }
        else if (!g.addEdge(Station(0, servicePointA), Station(0, servicePointB), capacity)) cout << "UNI ERROR" << endl;
    }
}

void Manager::addArtificialSource() {
    Station artificial = Station(0, "");
    g.addVertex(artificial);
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'R') {
            if (!g.addEdge(artificial, v->getInfo(), reservoirs.at(v->getInfo().getId()).getMaxDelivery())) cout << "ERROR IN ADDING SUPER SOURCE" << endl;
        }
    }
}

void Manager::maximumFlow(std::string city) {
    Station source = Station(0, ""); // Artificial super source
    Station target = Station(0, city);
    int answer = g.edmondsKarp(source, target);
    if (answer == -1) cout << "No water flows into: " << city << endl;
    else cout << "<" << city << "," << answer << ">" << endl;
}

void Manager::allCitiesMaximumFlow() {
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'C') {
            maximumFlow(v->getInfo().getCode());
        }
    }
}