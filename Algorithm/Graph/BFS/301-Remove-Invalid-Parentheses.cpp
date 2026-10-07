// leetcode POTD 7 Oct 2026 - 301. Remove Invalid Parentheses

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

vector<string> removeInvalidParentheses(string s) {
    int n = s.size();
    vector<string> res;

    queue<string> q;
    unordered_set<string> visited;

    q.push(s);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int j = 0; j < levelSize; j++) {
            string current = q.front();
            q.pop();

            visited.insert(current);

            int bal = 0;

            for (char c : current) {
                if (c == '(') {
                    bal++;
                } else if (c == ')') {
                    bal--;
                }

                if (bal < 0) {
                    break;
                }
            }

            if (bal == 0 && !current.empty()) {
                res.push_back(current);
            }

            for (int i = 0; i < current.size(); i++) {
                string next = current.substr(0, i) + current.substr(i + 1);

                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        if (!res.empty()) {
            return res;
        }
    }

    return {""};
}

// Overall time complexity is O(n * 2^n), where n is the length of the input string.
// This is because, in the worst case, we may need to generate all possible combinations of the string by removing parentheses,
// which can lead to 2^n combinations. For each combination, we check if it is valid, which takes O(n) time.

// Overall space complexity is O(n * 2^n) as well, since we are storing all the combinations in the queue and visited set.

// A backtracking solution exists as well, which can be more efficient in practice, but the BFS approach is straightforward and guarantees that we find the shortest valid strings first.