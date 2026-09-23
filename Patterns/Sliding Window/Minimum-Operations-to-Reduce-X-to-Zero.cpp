#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        int total = 0;
        for (int num : nums)
        {
            total += num;
        }

        int target = total - x;
        int current = 0;
        int ml = -1;

        int l = 0;
        for (int r = 0; r < n; r++)
        {
            current += nums[r];

            while (current > target && l <= r)
            {
                current -= nums[l];
                l++;
            }

            if (current == target)
                ml = max(ml, r - l + 1);
        }

        if (ml != -1)
            return n - ml;
        return -1;
    }
};

// Overall time complexity O(n) and space complexity O(1)