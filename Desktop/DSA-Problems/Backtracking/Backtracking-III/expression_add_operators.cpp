#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void dfs(string& num, int idx, long curr, long prev, long target, string path) {
        if (idx == num.size()) {
            if (curr == target)
                ans.push_back(path);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i != idx && num[idx] == '0') break;
            string s = num.substr(idx, i - idx + 1);
            long val = stol(s);

            if (idx == 0) {
                dfs(num, i + 1, val, val, target, s);
            } else {
                dfs(num, i + 1, curr + val, val, target, path + "+" + s);
                dfs(num, i + 1, curr - val, -val, target, path + "-" + s);
                dfs(num, i + 1,
                    curr - prev + prev * val,
                    prev * val,
                    target,
                    path + "*" + s);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        dfs(num, 0, 0, 0, target, "");
        return ans;
    }
};
