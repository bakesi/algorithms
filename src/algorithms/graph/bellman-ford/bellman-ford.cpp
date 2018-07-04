#include <cstdio>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAX_WEIGHT INT_MAX

class Graph
{
    vector<char> V;               // verticies
    map<char, vector<char>> Adj;  //adjacent
    map<pair<char, char>, int> W; // weights
    map<char, int> D;             // dynamic weights
    map<char, char> P;            // parent
    void initialize(const char);
    void relax(const char, const char);

  public:
    Graph(vector<char>, map<char, vector<char>>, map<pair<char, char>, int>);
    void search(const char);
    void printWeights(const char);
};

Graph::Graph(vector<char> _V, map<char, vector<char>> _Adj, map<pair<char, char>, int> _W)
{
    V = _V;
    Adj = _Adj;
    W = _W;
}

void Graph::initialize(const char s)
{
    D.clear();
    P.clear();
    for (const char &v : V)
    {
        D.insert({v, MAX_WEIGHT});
        P.insert({v, (char)0});
    }

    D[s] = 0;
}

void Graph::relax(const char u, const char v)
{
    if (D[u] < MAX_WEIGHT && D[v] > D[u] + W[{u, v}])
    {
        D[v] = D[u] + W[{u, v}];
        P[v] = u;
    }
}

void Graph::search(const char s)
{
    initialize(s);

    for (size_t i = 1; i < V.size(); ++i) {
        for (const auto e: W) {
            relax(e.first.first, e.first.second);
        }
    }

    printWeights(s);
}

void Graph::printWeights(const char s)
{
    printf("\n");
    printf("Weights from %c to\n", s);
    for (const auto it : D)
    {
        if (it.second < MAX_WEIGHT) {
            printf("%c: %d\n", it.first, it.second);
        } else {
            printf("%c: %s\n", it.first, "infinity");
        }
    }
}
