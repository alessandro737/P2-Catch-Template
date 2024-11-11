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

    for(int i = 0; i < n - 1; i++) {
        map<int, double> newRanks;

        // calculate contribution for pages
        for(const auto &pair : ranks) {
            int page = pair.first;
            double rank = pair.second;
            double contribution = rank / getOutDegree(page);

            for (int neighbor : getAdjacent(page)) {
                newRanks[neighbor] += contribution;
            }
        }
        //update ranks for next power iteration
        ranks = move(newRanks);

        // cout << "Iteration " << i + 1 << " ranks:\n";
        // for (const auto &pair : ranks) {
        //     cout << idToURL[pair.first] << ": " << pair.second << "\n";
        // }
    }

    double totalRank = 0.0;
    for(const auto &pair : ranks) {
        totalRank += pair.second;
    }
    for(auto &pair : ranks) {
        pair.second /= totalRank;
    }

    // Output PageRank Vals in Alpha order of URLs
    ostringstream oss;
    for(const auto &pair : urlToId) {
        const string &url = pair.first;
        int id = pair.second;
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

void Graph::insertEdge(const string& from, const string& to) {
    int fromId = getOrCreateId(from);
    int toId = getOrCreateId(to);
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
    double initialRank = 1.0 / urlToId.size();
    // cout << "Initial Rank: " << initialRank << endl;
    for (const auto& vertex : urlToId) {
        ranks[vertex.second] = initialRank;
    }
}

void Graph::printAdjList() const {
    cout << "Adjacency List:" << endl;
    for (const auto &pair : adjList) {
        int pageId = pair.first;
        cout << idToURL.at(pageId) << " -> ";
        for (int neighbor : pair.second) {
            cout << idToURL.at(neighbor) << " ";
        }
        cout << endl;
    }
}

void Graph::printOutDegrees() const {
    cout << "Out-Degrees:" << endl;
    for (const auto &pair : outDegree) {
        int pageId = pair.first;
        cout << idToURL.at(pageId) << " : " << pair.second << endl;
    }
}

int Graph::parseInput(const string &input) {
    istringstream iss(input);
    int no_of_lines, power_iterations;
    iss >> no_of_lines >> power_iterations;

    string from, to;
    for(int i = 0; i < no_of_lines; i++) {
        iss >> from >> to;
        insertEdge(from, to);
    }

    return power_iterations;
}

