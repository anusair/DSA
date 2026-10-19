#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        int l = 0;
        int r = n;
        int first = -1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] == target) {
                first = mid;
                r = mid;
            } else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }

        if (first == -1) return {};

        l = 0;
        r = n;
        int last = -1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] == target) {
                last = mid;
                l = mid + 1;
            } else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }

        vector<int> result(last - first + 1);
        iota(result.begin(), result.end(), first);
        return result;
    }
};

// If you're using C++, solve it using one for loop :)