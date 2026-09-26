// Sep 26 2026
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hm;

        for (auto &item : knowledge) {
            string k = item[0];
            string v = item[1];
            hm[k] = v;
        }

        int n = s.size();
        string ans = "";

        bool started = false; 
        string key = "";
        for (int i = 0 ; i < n; i++) {
            if (s[i] == '(') {
                started = true;
                key = "";
            } else if (s[i] == ')') {
                if (hm.find(key) != hm.end()) {
                    ans += hm[key];
                } else {
                    ans += "?";
                }

                started = false;
            } else {
                if (started) key += s[i];
                else ans += s[i];
            }


        }

        return ans;
    }
};

// Time complexity O(n), and space complexity O(n + total size of knowledge)