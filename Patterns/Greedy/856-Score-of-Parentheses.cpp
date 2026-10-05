// leetcode POTD 5 Oct 2026 
// 856. Score of Parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;

        int d = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(') d++;
            else {
                d--;
                if (s[i - 1] == '(') {
                    score += 1 << d;
                }
            }
        }

        return score;
    }
};

// Time complexity: O(n), and space complexity: O(1)