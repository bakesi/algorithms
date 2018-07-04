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
    char extractMin(vector<char> &);

  public:
    Graph(vector<char>, map<char, vector<char>>, map<pair<char, char>, int>);
    void search(const char, const char);
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

char Graph::extractMin(vector<char> &Q)
{
    char res = (char)0;
    for (const char &v : Q)
    {
        if (!res || D[v] < D[res])
        {
            res = v;
        }
    }
    Q.erase(std::remove(Q.begin(), Q.end(), res), Q.end());
    return res;
}

void Graph::search(const char s, const char d = (char)0)
{
    initialize(s);
    vector<char> Q = V; // min priority queue. @TODO: use Min Heap

    while (!Q.empty())
    {
        const char u = extractMin(Q); // @TODO: use Min Heap
        if (d && u == d)
            break;
        for (const char &v : Adj[u])
        {
            relax(u, v);
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
