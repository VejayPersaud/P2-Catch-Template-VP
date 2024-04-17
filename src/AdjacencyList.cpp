#include "AdjacencyList.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;


void AdjacencyList::addEdge(const string& from, const string& to) {
    //Ensure 'from' vertex is added to the graph
    if (myMap.find(from) == myMap.end()) {
        myMap[from] = vector<string>();
    }
    //Ensure 'to' vertex is also added to the graph
    if (myMap.find(to) == myMap.end()) {
        myMap[to] = vector<string>();
    }
    //Add the edge
    myMap[from].push_back(to);
}


void AdjacencyList::initializePageRank() {
    double initialRank = 1.0 / myMap.size();
    for (const auto& pair : myMap) {
        ranks[pair.first] = initialRank;
    }
}

void AdjacencyList::computePageRank(int power_iterations) {
    map<string, double> tempRanks = ranks; //Use a temporary map for calculations

    //Adjust the iteration count internally
    int adjustedIterations = power_iterations - 1;

    for (int i = 0; i < adjustedIterations; ++i) {
        //Initialize temporary ranks for this iteration
        for (auto& pair : tempRanks) {
            pair.second = 0.0;
        }

        //Distribute ranks based on the current state
        for (const auto& pair : myMap) {
            double fromRank = ranks[pair.first];
            int outDegree = pair.second.size();
            for (const auto& to : pair.second) {
                tempRanks[to] += fromRank / (outDegree ? outDegree : 1); //Prevent division by zero
            }
        }

        //Update ranks for the next iteration
        ranks = tempRanks;
    }
}



string AdjacencyList::PageRank(int power_iterations) {
    initializePageRank();
    computePageRank(power_iterations);

    vector<pair<string, double>> sortedRanks(ranks.begin(), ranks.end());
    sort(sortedRanks.begin(), sortedRanks.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; //Sort alphabetically by webpage name
    });

    stringstream ss;
    for (const auto& pair : sortedRanks) {
        ss << pair.first << " " << fixed << setprecision(2) << pair.second << "\n";
    }
    return ss.str();
}


int AdjacencyList::getAdjacencyListSize(const string& vertex) {
    auto it = myMap.find(vertex);
    if (it != myMap.end()) {
        //Vertex found, return the size of its adjacency list
        return it->second.size();
    } else {
        //Vertex not found, return 0
        return 0;
    }
}

pair<int,int> AdjacencyList::addEdgesFromString(const string& input) {
    istringstream stream(input);
    string line;
    getline(stream, line);

    //Parse the first line for the number of lines and power iterations
    int no_of_lines, power_iterations;
    istringstream firstLineStream(line);
    firstLineStream >> no_of_lines >> power_iterations;


    while (getline(stream, line)) {
        if (line.empty()) continue; //Skip empty lines
        istringstream linestream(line);
        string from, to;
        if (linestream >> from >> to) {
            addEdge(from, to);
        }
    }

    //Return the extracted information
    return {no_of_lines, power_iterations};




}

