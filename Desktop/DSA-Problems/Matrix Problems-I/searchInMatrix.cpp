#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int tar) {
    int m=mat.size();
    int n=mat[0].size();
    int targetRow;
    int sr=0,er=m-1,sc=0,ec=n-1;
    while(sr<=er){
        int midRow=sr+(er-sr)/2;
        if(tar>=mat[midRow][sc] && tar <=mat[midRow][ec]){
            targetRow=midRow;
            while(sc<=ec){
                int mid=sc+(ec-sc)/2;
                if(tar==mat[targetRow][mid]){
                    return true;
                }
                else if(tar<mat[targetRow][mid]){
                    ec=mid-1;
                }
                else{
                    sc=mid+1;
                }
            }
        }
        else if(tar<mat[midRow][sc]){
            er=midRow-1;
        }
        else{
            sr=midRow+1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>>mat={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int tar=29;
    if(searchMatrix(mat,tar)){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
}