#pragma once

#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Graph {
private:
    map<int, vector<int>> adjList;
    map<int, int> outDegree;
    map<string, int> urlToId;
    map<int, string> idToURL;
    //Think about what member variables you need to initialize
public:
    //Think about what helper functions you will need in the algorithm
    string pageRankAlgo(int n);
    int getOrCreateId(const string& url);
    void insertEdge(const string&  from, const string& to);
    const vector<int>& getAdjacent(int vertex) const;
    int getOutDegree(int vertex) const;
    vector<int> getVertices() const;
    void initializeRanks(map<int, double>& ranks) const;
    //debug functions
    void printAdjList() const;
    void printOutDegrees() const;
    //catch functions
    int parseInput(const string& input);
};

// This class and method are optional.
