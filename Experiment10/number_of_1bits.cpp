#include<iostream>
using namespace std;

// NUMBER OF 1 BITS (LEETCODE 191)
// USING BIT MANIPULATION - TC=O(N), SC=O(1)

int hammingWeight(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}