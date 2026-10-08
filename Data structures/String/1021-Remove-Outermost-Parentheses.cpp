// leetcode POTD 8 Oct 2026 - 1021. Remove Outermost Parentheses
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string res = "";

        for (char c : s) {
            if (c == '(') {
                depth++;

                if (depth > 1) {
                    res += c;
                }
            } else {
                depth--;

                if (depth > 0) {
                    res += c;
                }
            }
        }

        return res;
    }
};

// Time complexity O(n), and space complexity O(n)