#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

class AdjacencyList {
private:
    map<string, vector<string>> myMap; //Adjacency list
    map<string, double> ranks; //Maps each vertex to its PageRank

public:

    //Adds an edge from 'from' to 'to' in the graph
    void addEdge(const string& from, const string& to);

    //Computes the PageRank of each vertex in the graph
    void initializePageRank();

    void computePageRank(int power_iterations);

    string PageRank(int power_iterations);

    //New method to get the size of the adjacency list for a given vertex
    int getAdjacencyListSize(const string& vertex);


    pair<int,int> addEdgesFromString(const string &input);
};