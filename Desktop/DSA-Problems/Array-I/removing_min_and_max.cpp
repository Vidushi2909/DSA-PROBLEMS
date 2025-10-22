#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        if(n<=2) return n;
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mini]){
                mini=i;
            }
            if(nums[i] > nums[maxi]){
                maxi = i;
            }
        }
        int left = min(mini,maxi);
        int right = max(mini,maxi);

        return min({right+1,n-left,(left+1+n-right)});
    }
};



