// Leetcode POTD 13 Oct 2026 - 3727. Maximum Alternating Sum of Squares

#include <vector>
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0 ; i < n ; i++) nums[i] *= nums[i];
        sort(nums.begin(), nums.end());

        long long res = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            res += nums[r] - nums[l];
            l++;
            r--;
        }

        if (l == r) res += nums[r];
        return res;
    }
};

// Time complexity O(nlogn), and space complexity O(1)