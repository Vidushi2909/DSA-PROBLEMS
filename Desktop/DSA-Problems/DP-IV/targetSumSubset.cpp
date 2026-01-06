#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int targetSumWays(vector<int>&nums, int tar){
    int totalSum=0;
    for(int num:nums){
        totalSum+=num;
    }
    if(abs(tar)>totalSum) return 0;
    if(((tar+totalSum)%2) != 0)return 0;
    int s=(tar+totalSum)/2;
    vector<int>dp(s+1,0);
    dp[0]=1;
    for(int num:nums){
        for(int i=s;i>=num;i--){
            dp[i]+=dp[i-num];
        }
    }
    return dp[s];
}
int main(){
    vector<int>nums={1,1,1,1,1};
    int tar=3;
    cout<<targetSumWays(nums,tar)<<"\n";
}