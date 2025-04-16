#include<iostream>
using namespace std;

// IS GRAPH BIPARTITE (LEETCODE 785)
// USING BFS TRAVERSAL - TC=O(N+E), SC=O(N+E)

bool bfs(int i, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto it : graph[frontNode])
        {
            if (color[it] == -1)
            {
                color[it] = !color[frontNode];
                q.push(it);
            }
            else if (color[it] == color[frontNode])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, graph, color))
                return false;
        }
    }
    return true;
}
