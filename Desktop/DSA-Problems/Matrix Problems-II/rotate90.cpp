#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        int l=0;
        for(int j =0;j<n/2;j++){
        swap(matrix[i][j],matrix[i][n-1-j]);
    }
}
}
int  main(){
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(vector<int>vec:matrix){
        for(int val:vec){
            cout<<val<<"";
        }
        cout<<"\n";
    }
}