#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(vector<string> board, int row, int col,int n){
    //horizontally
    for(int j=0;j<n;j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    //vertically
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
         if(board[i][j]=='Q'){
            return false;
        }
    }
    //right diagonal
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nQueens(vector<string>&board, vector<vector<string>>&ans, int row, int n){
    //base case
    if(row>=n) {
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j]='Q';
            nQueens(board,ans,row+1,n);
            board[row][j]='.';
        }
    }
}
int main(){
    vector<string>board={"....","....","....","...."};
    int n=4;
    vector<vector<string>>ans;
    nQueens(board,ans,0,n);
    for(vector<string>vec:ans){
        cout<<"[";
        for(string str:vec){

            cout<<"["<<str<<"]";
        }
        cout<<"]";
        cout<<"\n";
    }
}