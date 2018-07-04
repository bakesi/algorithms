#include <cstdio>
#include <map>
#include <list>

using namespace std;

void printPath(const map<char, char> &parent, const char &s)
{
    char v = s;
    char p = s;
    printf("Path: %c", v);
    while (p)
    {
        p = (char)0;
        for (const auto &it : parent)
        {
            if (it.second == v)
            {
                p = it.first;
                break;
            }
        }

        if (p)
        {
            printf("->%c", p);
            v = p;
        }
    }
    printf("\n");
}

void printOrder(const list<char> &order)
{
    printf("Topological order:");
    for (const auto &it : order)
    {
        printf(" %c", it);
    }
    printf("\n");
}

void DFSvisit(map<char, char> &parent, list<char> &order, const map<char, list<char>> &Adj, const char &s)
{
    if (Adj.find(s) != Adj.end())
    {
        for (const char &v : Adj.at(s))
        {
            if (parent.find(v) == parent.end())
            {
                parent.insert(make_pair(v, s));
                DFSvisit(parent, order, Adj, v);
            }
        }
    }
    order.push_front(s);
}

void DFS(const list<char> &V, const map<char, list<char>> &Adj)
{
    map<char, char> parent;
    list<char> order;
    for (const char &s : V)
    {
        if (parent.find(s) == parent.end())
        {
            parent.insert(make_pair(s, NULL));
            DFSvisit(parent, order, Adj, s);
            printPath(parent, s);
        }
    }
    printOrder(order);
}
