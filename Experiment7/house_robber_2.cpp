#include<iostream>
using namespace std;

// HOUSE ROBBER II (LEETCODE 213)
// USING MEMOIZATION - TC=O(N), SC=O(N)

int solveUsingMem(int index, int n, vector<int> &dp, vector<int> &nums)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int include = nums[index] + solveUsingMem(index + 2, n, dp, nums);
    int exclude = 0 + solveUsingMem(index + 1, n, dp, nums);
    dp[index] = max(include, exclude);
    return dp[index];
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp1(n, -1);
    int ans1 = solveUsingMem(0, n - 1, dp1, nums);
    vector<int> dp2(n, -1);
    int ans2 = solveUsingMem(1, n, dp2, nums);
    return max(ans1, ans2);
}
