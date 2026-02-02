#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int count = 0;

    bool isPal(string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }

    void dfs(int idx, string &s) {
        if (idx == s.size()) {
            count++;
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                dfs(i + 1, s);
            }
        }
    }

    int countPartitions(string s) {
        dfs(0, s);
        return count;
    }
};
