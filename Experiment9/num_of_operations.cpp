#include<iostream>
using namespace std;

// NUMBER OF OPERATIONS TO MAKE NETWORK CONNECTED (LEETCODE 1319)
// USING DISJOINT SETS - TC=O(E+V), SC=O(V)

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int extraEdges = 0;
    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u != v)
        {
            unionSet(u, v, parent, rank);
        }
        else
        {
            extraEdges++;
        }
    }
    int connectedComp = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
        {
            connectedComp++;
        }
    }
    int ans = connectedComp - 1;
    return extraEdges >= ans ? ans : -1;
}