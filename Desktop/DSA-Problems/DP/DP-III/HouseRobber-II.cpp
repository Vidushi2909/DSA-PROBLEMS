#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int robRange(vector<int>&nums, int start, int end){
    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return nums[0];
    int len = end-start+1;
    vector<int>dp(len+1,0);
    dp[0]=0;
    dp[1]=nums[start];
    for(int i=2;i<=len;i++){
        dp[i]=max(dp[i-1],nums[start+i-1]+dp[i-2]);
    }
    return dp[len];
}
int rob(vector<int>& nums) {
    int n=nums.size();
        int first = robRange(nums,0,n-2);
        int last = robRange(nums,1,n-1);
        return max(first,last);
    }
int main(){
    vector<int>arr={1,2,3,1};
    cout<<rob(arr)<<"\n";
}