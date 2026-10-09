// leetcode POTD 9 Oct 2026 - 1541. Minimum Insertions to Balance a Parentheses String

#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int bal = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                if (bal % 2 != 0){
                    ans++;
                    bal--;
                }
                bal += 2;
            } else {
                if (bal == 0) {
                    ans++;
                    bal++;
                } else bal--;
            }
        }

        return ans + bal;
    }
};

// Time complexity O(n), and space complexity O(1)