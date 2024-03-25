#include "Manager.h"
#include <cstdint>

void Manager::initializeGraph(int i) {
    readReservoirs(i);
    readStations(i);
    readCities(i);
    readPipes(i);
    addArtificialSource();
    addArtificialSink();
}

void Manager::readReservoirs(int i) {
    string j;
    if (i == 1) {
        j = "../Project1DataSetSmall/Reservoirs_Madeira.csv";
    } else if (i == 2) {
        j = "../Project1LargeDataSet/Reservoir.csv";
    }
    fstream file(j);

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

void Manager::readStations(int i) {
    string j;
    if (i == 1) {
        j = "../Project1DataSetSmall/Stations_Madeira.csv";
    } else if (i == 2) {
        j = "../Project1LargeDataSet/Stations.csv";
    }
    fstream file(j);

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

void Manager::readCities(int i) {
    string j;
    if (i == 1) {
        j = "../Project1DataSetSmall/Cities_Madeira.csv";
    } else if (i == 2) {
        j = "../Project1LargeDataSet/Cities.csv";
    }
    fstream file(j);

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

void Manager::readPipes(int i) {
    string j;
    if (i == 1) {
        j = "../Project1DataSetSmall/Pipes_Madeira.csv";
    } else if (i == 2) {
        j = "../Project1LargeDataSet/Pipes.csv";
    }
    fstream file(j);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    string line;
    getline(file, line); // Ignore header
    int id = 0;
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

        pipes.insert({id, temp});
        id++;

        if (!direction) {
            if (!g.addBidirectionalEdge(Station(0, servicePointA), Station(0, servicePointB), capacity)) cout << "BIDIRECTION ERROR" << endl;
        }
        else if (!g.addEdge(Station(0, servicePointA), Station(0, servicePointB), capacity)) cout << "UNI ERROR" << endl;
    }
}

void Manager::addArtificialSource() {
    Station artificial = Station(0, "SuperSource");
    g.addVertex(artificial);
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'R') {
            if (!g.addEdge(artificial, v->getInfo(), reservoirs.at(v->getInfo().getId()).getMaxDelivery())) cout << "ERROR IN ADDING SUPER SOURCE" << endl;
        }
    }
}

void Manager::addArtificialSink() {
    Station artificial = Station(0, "SuperSink");
    g.addVertex(artificial);
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'C') {
            int demand = cities.at(v->getInfo().getId()).getDemand();
            if (!g.addEdge(v->getInfo(), artificial, demand)) cout << "ERROR IN ADDING SUPER SINK" << endl;
        }
    }
}

int Manager::initiateEdmondsKarp() {
    Station source = Station(0, "SuperSource"); // Artificial super source
    Station target = Station(0, "SuperSink"); // Artificial super sink
    return g.edmondsKarp(source, target);
}

void Manager::maximumFlow(std::string city) {
    Station source = Station(0, "SuperSource");
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

void Manager::allCitiesMaximumFlow2() {
    int answer = initiateEdmondsKarp();
    cout << "MAXIMUM FLOW OF THE NETWORK: " << answer << endl;
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'C') {
            for (Edge<Station>* e : v->getAdj()) {
                if (e->getDest()->getInfo().getCode() == "SuperSink") {
                    cout << "<" << v->getInfo().getCode() << "," << e->getFlow() << ">" << endl;
                }
            }
        }
    }
}

void Manager::reservoirDeficit() {
    initiateEdmondsKarp();
    cout << "DEFICIT FLOW OF THE NETWORK:" << endl;
    for (Vertex<Station>* v : g.getVertexSet()) {
        if (v->getInfo().getCode()[0] == 'C') {
            for (Edge<Station>* e : v->getAdj()) {
                if (e->getDest()->getInfo().getCode() == "SuperSink" && (cities.at(v->getInfo().getId()).getDemand() > e->getFlow())) {
                    cout << "<" << v->getInfo().getCode() << "," << cities.at(v->getInfo().getId()).getDemand() - e->getFlow() << ">" << endl;
                }
            }
        }
    }
}

void Manager::initialMetrics() {
    initiateEdmondsKarp();
    cout << "INITIAL METRICS:" << endl;
    double sum_diff = 0.0;
    double sum_squared_diff = 0.0;
    double max_diff = 0.0;

    for (pair<const int, Pipe> pipe : pipes) {
        auto &pipe_ = pipe.second;
        int flow = calculatePipeFlow(pipe_.getServicePointA(), pipe_.getServicePointB());
        double diff = pipe_.getCapacity() - flow;
        sum_diff += diff;
        sum_squared_diff += pow(diff, 2);
        max_diff = std::max(max_diff, diff);
    }
    double avg_diff = sum_diff / pipes.size();
    double variance = sum_squared_diff / pipes.size() - pow(avg_diff, 2);
    cout << "INITIAL AVERAGE -> " << avg_diff << endl
         << "INITIAL VARIANCE -> " << variance << endl
         << "INITIAL MAXIMUM DIFFERENCE -> " << max_diff << endl;
}

void Manager::finalMetrics() {
    gradientDescent();
    cout << "FINAL METRICS:" << endl;
    double sum_diff = 0.0;
    double sum_squared_diff = 0.0;
    double max_diff = 0.0;
    for (pair<const int, Pipe> pipe : pipes) {
        auto &pipe_ = pipe.second;
        int flow = calculatePipeFlow(pipe_.getServicePointA(), pipe_.getServicePointB());
        double diff = pipe_.getCapacity() - flow;
        sum_diff += diff;
        sum_squared_diff += pow(diff, 2);
        max_diff = std::max(max_diff, diff);
    }
    double avg_diff = sum_diff / pipes.size();
    double variance = sum_squared_diff / pipes.size() - pow(avg_diff, 2);
    cout << "FINAL AVERAGE -> " << avg_diff << endl
         << "FINAL VARIANCE -> " << variance << endl
         << "FINAL MAXIMUM DIFFERENCE -> " << max_diff << endl;
}

int Manager::calculatePipeFlow(string a, string b) {
    Station source = Station(0, a);
    Station target = Station(0, b);
    Vertex<Station>* s = g.findVertex(source);
    double flow = 0;
    for (Edge<Station>* e : s->getAdj()) {
        if (auto w = e->getDest(); w->getInfo().getCode() == b) flow = e->getFlow();
    }
    return flow;
}

void Manager::pipelinesFailures(string cityCode) {
    Station target = Station(0, cityCode);
    Station source = Station(0, "SuperSource");
    double temp;

    for (Vertex<Station>* s: g.getVertexSet()) {
        for (Edge<Station>* e : s->getAdj()) {
            e->setSelected(false);
            if (e->getDest()->getInfo().getCode() == "SuperSink") e->setSelected(true);
            if (e->getOrig()->getInfo().getCode() == "SuperSource") e->setSelected(true);
        }
    }

    std::cout << "Critical Pipes to: " << cityCode << endl;
    Vertex<Station>* city = g.findVertex(target);
    for (Vertex<Station>* s: g.getVertexSet()) {
        for (Edge<Station>* e : s->getAdj()) {
            if (!e->isSelected()) {
                temp = e->getWeight();
                e->setWeight(0);
                if (e->getReverse() != nullptr) e->getReverse()->setWeight(0);
                g.edmondsKarp(source, target);
                e->setWeight(temp);
                if (e->getReverse() != nullptr) e->getReverse()->setWeight(temp);
                if (city->getFlowRate() <= cities.at(city->getInfo().getId()).getDemand()) {
                    std::cout << e->getOrig()->getInfo().getCode() << " -> " << e->getDest()->getInfo().getCode() << endl;
                }
            }
            e->setSelected(true);
            if (e->getReverse() != nullptr) e->getReverse()->setSelected(true);
        }
    }
}

void Manager::affectedCitiesByPipelines() {
    initiateEdmondsKarp();
    vector<double> originalValues;
    bool PrintOneTime = true;

    for (Vertex<Station>* s: g.getVertexSet()) {
        if (s->getInfo().getCode()[0] == 'C') {
            originalValues.push_back(s->getFlowRate());
        }
        for (Edge<Station>* e : s->getAdj()) {
            e->setSelected(false);
            if (e->getDest()->getInfo().getCode() == "SuperSink") e->setSelected(true);
            if (e->getOrig()->getInfo().getCode() == "SuperSource") e->setSelected(true);
        }
    }

    for (Vertex<Station> *s : g.getVertexSet()) {
        for (Edge<Station> *e : s->getAdj()) {
            if (!e->isSelected()) {
                double t = e->getWeight();
                e->setWeight(0);
                if (e->getReverse() != nullptr) e->getReverse()->setWeight(0);
                initiateEdmondsKarp();
                e->setWeight(t);
                if (e->getReverse() != nullptr) e->getReverse()->setWeight(t);
                int count = 0;
                for (Vertex<Station> *p : g.getVertexSet()) {
                    if (p->getInfo().getCode()[0] != 'C') continue;
                    if (p->getFlowRate() < originalValues[count]) {
                        if (PrintOneTime) {
                        std::cout << "This pipeline " << e->getOrig()->getInfo().getCode() << " -> " << e->getDest()->getInfo().getCode()
                                  << " affects: " << endl;
                        PrintOneTime = false;
                        }
                        std::cout << "     -City: " << p->getInfo().getCode() << ", Deficit: " << originalValues[count] - p->getFlowRate() << endl;
                    }
                    count++;
                }
                PrintOneTime = true;

            }
            e->setSelected(true);
            if (e->getReverse() != nullptr) e->getReverse()->setSelected(true);
        }
    }
}

void Manager::affectedCitiesByPumping() {
    initiateEdmondsKarp();
    vector<double> originalValues;

    bool PrintOneTime = true;

    for (Vertex<Station>* s: g.getVertexSet()) {
        if (s->getInfo().getCode()[0] == 'C') {
            originalValues.push_back(s->getFlowRate());
        }
    }

    for (Vertex<Station>* s: g.getVertexSet()) {
        if (s->getInfo().getCode()[0] != 'P') continue;
        bool affected_at_least_one_city = false;
        vector<double> capacities = setZeroAndSaveCapacity(s);
        initiateEdmondsKarp();
        int count = 0;
        for (Vertex<Station> *p : g.getVertexSet()) {
            if (p->getInfo().getCode()[0] != 'C') continue;
            if (p->getFlowRate() < originalValues[count]) {
                affected_at_least_one_city = true;
                if (PrintOneTime) {
                    std::cout << "The pumping " << s->getInfo().getCode() << " affects: " << endl;
                    PrintOneTime = false;
                }
                std::cout << "     -City: " << p->getInfo().getCode() << ", Deficit: " << originalValues[count] - p->getFlowRate() << endl;
            }
            count++;
        }
        if (!affected_at_least_one_city) {
            std::cout << "The pumping " << s->getInfo().getCode() << " doesn't affect any city if removed" << endl;
        }
        PrintOneTime = true;

        int k = 0;
        for (Edge<Station>* e : s->getIncoming()) {
            e->setWeight(capacities[k++]);
        }

    }
}

vector<double> Manager::setZeroAndSaveCapacity(Vertex<Station>* v) {
    vector<double> capacities;
    for (Edge<Station>* e : v->getIncoming()) {
        capacities.push_back(e->getWeight());
        e->setWeight(0);
    }
    return capacities;
}

void Manager::affectedCitiesByReservoirs(string reservoirCode) {
    initiateEdmondsKarp();
    Station target = Station(0, reservoirCode);
    Vertex<Station>* reservoir = g.findVertex(target);
    vector<double> originalValues;
    vector<double> capacities;
    bool PrintOneTime = true;

    for (Vertex<Station>* s: g.getVertexSet()) {
        if (s->getInfo().getCode()[0] == 'C') {
            originalValues.push_back(s->getFlowRate());
        }
    }
    for (Edge<Station>* e: reservoir->getAdj()) {
        capacities.push_back(e->getWeight());
        e->setWeight(0);
    }
    initiateEdmondsKarp();

    int count = 0;
    for (Vertex<Station> *p : g.getVertexSet()) {
        if (p->getInfo().getCode()[0] != 'C') continue;
        if (p->getFlowRate() < originalValues[count]) {
            if (PrintOneTime) {
                std::cout << "The reservoir " << reservoir->getInfo().getCode() << " affects: " << endl;
                PrintOneTime = false;
            }
            std::cout << "     -City: " << p->getInfo().getCode() << ", Deficit: " << originalValues[count] - p->getFlowRate() << endl;
        }
        count++;
    }
    PrintOneTime = true;

    int k = 0;
    for (Edge<Station>* e : reservoir->getAdj()) {
        e->setWeight(capacities[k++]);
    }
}

double Manager::computeObjectiveFunction() {
    double obj = 0.0;
    for (auto v : g.getVertexSet()) {
        for (auto e : v->getAdj()) {
            double deviation = e->getWeight() - e->getFlow();
            obj += deviation * deviation; // non-negative numbers
        }
    }
    return obj;
}

void Manager::computeGradient() {
    for (auto v : g.getVertexSet()) {
        for (auto e : v->getAdj()) {
            double deviation = e->getWeight() - e->getFlow();
            double gradient = -2.0 * deviation;
            e->setGradient(gradient);
        }
    }
}

void Manager::updateFlowValues(double learningRate) {
    for (auto v : g.getVertexSet()) {
        for (auto e : v->getAdj()) {
            double gradient = e->getGradient();
            double initialFlow = e->getFlow();
            double finalFlow = initialFlow - learningRate * gradient;
            finalFlow = std::max(0.0, std::min(finalFlow, e->getWeight()));
            e->setFlow(finalFlow);
        }
    }
}

void Manager::gradientDescent() {
    double learningRate = 0.01;
    double convergence = 1e-6;
    double prevObj = std::numeric_limits<double>::infinity();
    while (true) {
        computeGradient();
        updateFlowValues(learningRate);
        double obj = computeObjectiveFunction();
        if (std::abs(obj - prevObj) < convergence) break;
        prevObj = obj;
    }
}

void Manager::improvedAffectedCitiesByReservoirs() {
    initiateEdmondsKarp();

    for (Vertex<Station> *v: g.getVertexSet()) {
        if (v->getInfo().getCode()[0] != 'R') continue;

    }
}