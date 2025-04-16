#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    int m = s.size(), n = goal.size();
    if (m != n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        bool rotationPossible = true;
        for (int j = 0; j < m; j++)
        {
            if (goal[(i + j) % n] != s[j])
            {
                rotationPossible = false;
                break;
            }
        }
        if (rotationPossible)
        {
            return true;
        }
    }
    return false;
}