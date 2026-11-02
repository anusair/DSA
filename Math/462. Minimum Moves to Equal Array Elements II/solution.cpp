// 2 Nov 2026 POTD - 462. Minimum Moves to Equal Array Elements II
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int md = nums[floor(n / 2)];
        int res = 0;
        for (int i = 0 ; i < n ; i++) res += abs(nums[i] - md);
        return res;
    }
};