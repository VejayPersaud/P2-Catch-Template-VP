#include "AdjacencyList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;


int main() {

    //Create a graph object
    AdjacencyList myGraph;

    //read first number of lines from cin
    int no_of_lines;
    cin >> no_of_lines;

//read the number of power iterations p from cin
    int power_iterations;
    cin >> power_iterations;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the leftover newline character


// for each of the next n lines, read in the vertices from and to
    for(int i = 0; i < no_of_lines; i++){
        string line;
        getline(cin,line);
        istringstream in(line);

        //read in the source vertex
        string from;
        in >> from;

        //read in the destination vertex
        string to;
        in >> to;

        myGraph.addEdge(from,to);


    }


    //Use the graph
    string tomato = myGraph.PageRank(power_iterations);
    cout << tomato << endl;
}
