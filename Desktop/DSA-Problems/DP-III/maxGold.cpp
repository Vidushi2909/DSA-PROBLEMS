#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxGold(vector<vector<int>>& mat, int r, int c,int n, int m) {
    if(r<0 || c<0 || r>=n || c>=m || mat[r][c]==0)return  0;
    int gold=mat[r][c];
    mat[r][c]=0;
    int best=0;
    best=max(best,maxGold(mat,r+1,c,n,m));
    best=max(best,maxGold(mat,r,c-1,n,m));
    best=max(best,maxGold(mat,r,c+1,n,m));
    best=max(best,maxGold(mat,r-1,c,n,m));
    mat[r][c]=gold;
    return gold+best;
}
int main(){
    vector<vector<int>>mat={{0,6,0}, {5,8,7}, {0,9,0}};
    int n=mat.size();
    int m=mat[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] > 0) {
                ans = max(ans, maxGold(mat, i, j, n, m));
            }
        }
    }

    cout << ans << "\n";
}