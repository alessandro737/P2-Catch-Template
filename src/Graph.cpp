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
            int outLinks = getOutDegree(page);

            if(outLinks > 0) {
                double contribution = rank / outLinks;
                for (int neighbor: getAdjacent(page)) {
                    newRanks[neighbor] += contribution;
                }
            }
        }

        //update ranks for next power iteration
        ranks = std::move(newRanks);

        // Debuggin Purposes

//         cout << "Iteration " << i + 1 << " ranks:\n";
//         for (const auto &pair : ranks) {
//             cout << idToURL[pair.first] << ": " << pair.second << "\n";
//         }
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
    static const vector<int> empty;
    auto it = adjList.find(vertex);
    return it != adjList.end() ? it->second : empty;
}

int Graph::getOutDegree(int vertex) const {
    //If outDegree does not exist return 0
    return outDegree.count(vertex) ? outDegree.at(vertex) : 0;
}

void Graph::initializeRanks(map<int, double> &ranks) const {
    double initialRank = 1.0 / urlToId.size();
//    cout << "Initial Rank: " << initialRank << endl;
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

