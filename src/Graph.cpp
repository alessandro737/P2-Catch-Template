#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string Graph::pageRankAlgo(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    map<int, double> ranks;
    initializeRanks(ranks);

    for(int i = 0; i < n; i++) {
        map<int, double> newRanks;

        for(const auto &[page, rank] : ranks) {
            double contribution = rank / getOutDegree(page);
            for (int neighbor : getAdjacent(page)) {
                newRanks[neighbor] += contribution;
            }
        }
        ranks = newRanks;
    }

    ostringstream oss;
    for(const auto &[url, id] : urlToId) {
        oss << url << " " << fixed << setprecision(2) << ranks[id] << "\n";
    }

    cout << oss.str();
    return oss.str();
}

int Graph::getOrCreateId(const string &url) {
    if(urlToId.find(url) == urlToId.end()) {
        int newId = urlToId.size();
        urlToId[url] = newId;
        idToURL[newId] = url;
    }
    return urlToId[url];
}

void Graph::insertEdge(int from, int to) {
    int fromId = getOrCreateId(idToURL[from]);
    int toId = getOrCreateId(idToURL[to]);
    adjList[fromId].push_back(toId);
    outDegree[fromId]++;
}

const vector<int>& Graph::getAdjacent(int vertex) const {
    return adjList.at(vertex);
}

int Graph::getOutDegree(int vertex) const {
    return outDegree.count(vertex) ? outDegree.at(vertex) : 0;
}

vector<int> Graph::getVertices() const {
    vector<int> result;
    for (const auto& vertex : adjList) {
        result.push_back(vertex.first);
    }
    return result;
}

void Graph::initializeRanks(map<int, double> &ranks) const {
    double initialRank = 1.0 / adjList.size();
    for (const auto& vertex : adjList) {
        ranks[vertex.first] = initialRank;
    }
}

