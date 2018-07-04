#include <cstdio>
#include <vector>
#include <map>
#include "bfs.cpp"

using namespace std;

int main()
{
    const vector<char> V = {'r', 'v', 's', 'w', 't', 'x', 'u', 'y'};

    const map<char, vector<char>> Adj = {
        {'r', {'v', 's'}},
        {'v', {'r'}},
        {'s', {'r', 'w'}},
        {'w', {'s', 't', 'x'}},
        {'t', {'w', 'x', 'u'}},
        {'x', {'w', 't', 'u', 'y'}},
        {'u', {'t', 'x', 'y'}},
        {'y', {'x', 'u'}}};
    BFS(Adj, 's');
    return 0;
}
