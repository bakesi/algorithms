#include <map>
#include <list>
#include "dfs.cpp"

using namespace std;

int main()
{
    const list<char> V = {'a', 'b', 'c', 'd', 'e', 'f'};

    const map<char, list<char>> Adj = {
        {'a', {'b', 'd'}},
        {'b', {'e'}},
        {'c', {'e', 'f'}},
        {'e', {'d'}},
        {'f', {'f'}},
    };
    DFS(V, Adj);
    return 0;
}
