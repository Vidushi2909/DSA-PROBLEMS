#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount=0,maxRow=0;
        int count=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count>maxCount){
                maxCount=count;
                maxRow=i;
            }
        }
        return {maxRow,maxCount};
    }
int  main(){
    // vector<vector<int>>mat={{0,0,0},{0,1,1}};
    vector<vector<int>>mat={{0,1},{1,0}};
    vector<int>ans=rowAndMaximumOnes(mat);
    for(int val:ans){
        cout<<val<<"";
    }
    cout<<"\n";
}