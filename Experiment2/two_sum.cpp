#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = i;
        int value = nums[i];
        p.push_back({value, index});
    }
    sort(p.begin(), p.end());
    int start = 0;
    int end = nums.size() - 1;
    vector<int> ans;
    while (start < end)
    {
        int sum = p[start].first + p[end].first;
        if (sum == target)
        {
            ans.push_back(p[start].second);
            ans.push_back(p[end].second);
            return ans;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}
