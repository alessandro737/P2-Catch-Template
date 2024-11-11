#pragma once

#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Graph {
private:
    //adjList map with urls mapped to a vector of url outgoing links
    map<int, vector<int>> adjList;
    //maps the count of outgoing links of a specific url
    map<int, int> outDegree;

    //These maps are for the ability to convert from string urls
    //to unique IDs and back; useful for reducing time computing
    //output of pagerank algorithm and for inserting edges.

    //maps url to ID
    map<string, int> urlToId;
    //maps id to url
    map<int, string> idToURL;

    //private member functions for instantiating adjList of Page Rank
    int getOrCreateId(const string& url);
    void initializeRanks(map<int, double>& ranks) const;
public:
    //Think about what helper functions you will need in the algorithm
    string pageRankAlgo(int n);
    void insertEdge(const string&  from, const string& to);
    const vector<int>& getAdjacent(int vertex) const;
    int getOutDegree(int vertex) const;

    //debug functions
    void printAdjList() const;
    void printOutDegrees() const;

    //catch functions
    int parseInput(const string& input);
};

