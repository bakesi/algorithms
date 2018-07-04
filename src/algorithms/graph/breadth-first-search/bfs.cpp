#include <cstdio>
#include <vector>
#include <map>

using namespace std;

void printLevels(const map<char, int> &level, const char s)
{
    for (auto it = level.begin(); it != level.end(); it++)
    {
        printf("%c->%c: %d\n", s, it->first, it->second);
    }
}

void BFS(const map<char, vector<char>> &Adj, const char s)
{
    map<char, int> level;
    level.insert(pair<char, int>{s, 0});
    map<char, char> parent;
    parent.insert(pair<char, char>{s, NULL});
    int i = 0;
    vector<char> frontier = {s};
    while (!frontier.empty())
    {
        i++;
        vector<char> next = {};
        for (const char &u : frontier)
        {
            for (const char &v : Adj.find(u)->second)
            {
                if (level.find(v) == level.end())
                {
                    level.insert(pair<char, int>{v, i});
                    parent.insert(pair<char, char>{v, u});
                    parent[v] = u;
                    next.push_back(v);
                }
            }
        }
        frontier = next;
    }

    printLevels(level, s);
}
