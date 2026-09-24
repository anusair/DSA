class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        sort(nums.begin() , nums.end());

        int total = 0;
        for (int num : nums) total += num;

        int accu = 0;
        for (int i = n - 1 ; i > -1 ; i--) {
            accu += nums[i];
            res.push_back(nums[i]);

            if (accu > total - accu) return res;
        }

        return nums;
    }
};

/*
Overall time complexity is O(n log n) and space complexity is O(n)
*/