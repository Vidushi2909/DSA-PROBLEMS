#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans(nums);
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]=ans[(n+i-k)%n];
        }
    }
};