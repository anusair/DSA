// leetcode POTD 6 Oct 2026
// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        int bal = 0;
        for (char c : s) {
            if (c == '(') { 
                st.push(c);
                bal++;
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    bal--;
                } else {
                    bal++;
                }
            }

        }

        return bal;
    }
};

// Time complexity: O(n), and space complexity: O(n)


/* 
However, two variables can be used instead of a stack: one to keep track of
open parentheses and the other to keep track of unmatched closed parentheses.
The first variable is incremented when an open parenthesis is encountered.
When a closed parenthesis is encountered, the first variable is decremented
if its value is greater than 0; otherwise, the second variable is incremented.

The final answer will be the sum of the two variables.
This reduces the space complexity to O(1).
*/
