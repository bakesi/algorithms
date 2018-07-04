#include <map>
#include <vector>
#include "bellman-ford.cpp"

using namespace std;

int main()
{
    Graph G(
        {'A', 'B', 'C', 'D', 'E'},
        {{'A', {'B', 'C'}},
         {'B', {'C', 'D'}},
         {'C', {'B', 'D', 'E'}},
         {'D', {'E'}},
         {'E', {'D'}}},
        {{{'A', 'B'}, 10},
         {{'A', 'C'}, 3},
         {{'B', 'C'}, 1},
         {{'B', 'D'}, 2},
         {{'C', 'B'}, 4},
         {{'C', 'D'}, 8},
         {{'C', 'E'}, 2},
         {{'D', 'E'}, 7},
         {{'E', 'D'}, 9}});

    G.search('A');
    G.search('B');
    return 0;
}
