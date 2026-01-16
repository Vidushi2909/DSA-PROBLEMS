#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCost(vector<int>&cost) {
    if(cost.size()==0) return 0;
    cost.push_back(0);
    int n = cost.size();
    vector<int>dp(n+1,0);
    dp[1]=cost[0];
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-2]+cost[i-1] , dp[i-1]+cost[i-1]);
    }
    return dp[n];
}

int main(){
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};
    cout<<minCost(cost)<<"\n";
}