#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n=s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]==s[j]){
                dp[i][j]=2+dp[i+1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s)<<"\n";
}