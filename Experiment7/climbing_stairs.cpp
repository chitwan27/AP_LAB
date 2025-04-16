#include<iostream>
using namespace std;

// CLIMBING STAIRS (LEETCODE 70)
// USING MEMOIZATION - TC=O(N), SC=O(N)

int solve(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];
    int oneStep = solve(n - 1, dp);
    int twoStep = solve(n - 2, dp);
    return dp[n] = oneStep + twoStep;
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}