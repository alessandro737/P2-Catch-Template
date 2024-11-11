#include "Graph.h"

#include <iostream>

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;

    Graph pageGraph;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        pageGraph.insertEdge(from, to);
    }

    //Debug Purposes
//     pageGraph.printAdjList();
//     pageGraph.printOutDegrees();

    string output = pageGraph.pageRankAlgo(power_iterations);

    return 0;
}
