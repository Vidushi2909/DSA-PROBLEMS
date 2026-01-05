#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxGold(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>dp(n+2,vector<int>(m+1,0));
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=mat[i-1][j-1]+max({dp[i-1][j-1] , dp[i][j-1], dp[i+1][j-1]});
        }
    }
    int maxgold=0;
    for(int i=0;i<=n;i++){
        maxgold=max(maxgold,dp[i][m]);
    }
    return maxgold;
}
int main(){
    vector<vector<int>>vec={{1, 3, 1, 5}, {2, 2, 4, 1}, {5, 0, 2, 3}, {0, 6, 1, 2}};
    cout<<maxGold(vec)<<"\n";
}