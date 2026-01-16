#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

int stairs(int n){
    if(n<=1) return 1;
    vector<int>dp(n+1,0);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int  main(){
    int n=3;
    cout<<stairs(n)<<"\n";
}