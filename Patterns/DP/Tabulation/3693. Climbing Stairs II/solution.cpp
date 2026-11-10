#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        costs.insert(costs.begin(), 0);
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int jump = 1; jump <= 3; jump++)
            {
                int j = i + jump;
                if (j <= n)
                {
                    dp[j] = min(dp[j], dp[i] + costs[j] + (j - i) * (j - i));
                }
            }
        }

        return dp[n];
    }
};