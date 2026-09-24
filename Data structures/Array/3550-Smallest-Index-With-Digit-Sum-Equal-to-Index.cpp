class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            while (nums[i] > 0)
            {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }

            if (sum == i)
                return i;
        }

        return -1;
    }
};

/*
Time complexity: O(n · d), where d is the maximum number of digits. Since nums[i] <= 1000, d <= 4, so the time complexity simplifies to O(n).
Space complexity: O(1).
*/