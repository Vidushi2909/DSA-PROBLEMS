#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    if(grid[0][0] ==1) return 0;
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(grid[i-1][j-1] == 0) {
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}

int main(){
    vector<vector<int>>grid={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles(grid)<<"\n";
}