#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool bt(int i , string& s , int bal , int n , vector<vector<int>>& memo) {
        if (bal < 0) return false;

        if (i >= n) {
            return bal == 0;
        }

        if (memo[i][bal] != -1) return memo[i][bal];


        if (s[i] == '(') {
            return memo[i][bal] = bt(i + 1 , s , bal + 1 , n , memo);
        } else if (s[i] == ')') {
            return memo[i][bal] = bt(i + 1 , s , bal - 1 , n , memo);
        } else {
            return memo[i][bal] = (
                bt(i + 1 , s , bal + 1 , n , memo) || 
                bt(i + 1 , s , bal - 1 , n , memo) ||
                bt(i + 1 , s , bal , n , memo)
            );
        }
    }

    bool checkValidString(string s) {
        int n = s.length();

        vector<vector<int>> memo(n , vector<int>(n + 1 , -1));
        return bt(0 , s , 0 , n , memo);
    }
};