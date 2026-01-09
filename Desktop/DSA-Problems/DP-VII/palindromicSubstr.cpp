#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int countPalindromeSubstr(string s){
    int n=s.length();
    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    int count=0;
    for(int i=0;i<n;i++){
        dp[i][i]=true;
        count++;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if((s[i]==s[j]) && (len<=2 ||dp[i+1][j-1])){
                dp[i][j]=true;
                count++;
            }
        }
    }
    return count;
}


int main(){
    string s = "bbabb";
    cout<<countPalindromeSubstr(s)<<"\n";
}