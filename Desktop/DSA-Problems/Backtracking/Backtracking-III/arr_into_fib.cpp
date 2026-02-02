#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool dfs(string& s, int idx, vector<int>& seq) {
        if (idx == s.size() && seq.size() >= 3)
            return true;

        long num = 0;
        for (int i = idx; i < s.size(); i++) {
            if (i > idx && s[idx] == '0') break;
            num = num * 10 + (s[i] - '0');
            if (num > INT_MAX) break;

            int n = seq.size();
            if (n >= 2 && num != (long)seq[n-1] + seq[n-2])
                continue;

            seq.push_back(num);
            if (dfs(s, i + 1, seq)) return true;
            seq.pop_back();
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        vector<int> seq;
        dfs(num, 0, seq);
        return seq;
    }
};
