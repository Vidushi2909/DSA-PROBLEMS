#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>>&mat){
    int m=mat.size();
    int n=mat[0].size();
    vector<int>result;
    int sr=0,sc=0,er=m-1,ec=n-1;
    while(sr<=er && sc<=ec){
        //top
        for(int j=sc;j<=ec;j++){
            result.push_back(mat[sr][j]);
        }
        //right
        for(int i=sr+1;i<=er;i++){
            result.push_back(mat[i][ec]);
        }
        //bottom
        if(sc==ec) break;
        for(int j=ec-1;j>=0;j--){
            result.push_back(mat[er][j]);
        }
        //left
        if(sr==er) break;
        for(int i=er-1;i>0;i--){
            result.push_back(mat[i][sc]);
        }

        sr++;
        ec--;
        er--;
        sc++;
    }
    return result;
}
int main(){
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans=spiralTraversal(mat);
    for(int val:ans){
        cout<<val<<",";
    }
    cout<<"\n";
}