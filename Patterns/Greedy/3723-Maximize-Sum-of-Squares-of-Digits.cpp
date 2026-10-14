// leetcode POTD 14 Oct 2026 - 3723. Maximize Sum of Squares of Digits

#include <string>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string res = "";
        for (int i = 0 ; i < num ; i++) {
            int digit = min(9 , sum);
            sum -= digit;
            res += to_string(digit);
        }

        if (sum != 0) return "";
        return res;
    }
};

// Time complexity O(n), and space complexity O(1)