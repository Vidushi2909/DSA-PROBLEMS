#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    int n=s.length();
    vector<vector<bool>>dp(n,vector<bool>(n,false));

    int st=0,maxLen=1;

    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]==s[j] && (len==2 || dp[i+1][j-1])){
                dp[i][j]=true;
                if(len>maxLen){
                    st=i;
                    maxLen=len;
                }
            }
        }
    }
    return s.substr(st,maxLen);
}
int main(){
    string text = "babad";
    cout<<longestPalindrome(text)<<"\n";
}