#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        vector<string> res;

        if (s.empty()) {
            res.push_back("");
            return res;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> sub = dfs(s.substr(i), dict);
                for (string t : sub) {
                    res.push_back(word + (t.empty() ? "" : " " + t));
                }
            }
        }
        return memo[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};
