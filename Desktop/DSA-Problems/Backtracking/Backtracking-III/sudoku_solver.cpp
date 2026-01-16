#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(vector<vector<char>>&board, int r, int c, char val){
    //horizontal
    for(int j=0;j<9;j++){
        if(board[r][j]==val){
            return false;
        }
    }
    //vertical
    for(int i=0;i<9;i++){
        if(board[i][c]==val){
            return false;
        }
    }
    //box
    int sr=(r/3)*3;
    int sc=(c/3)*3;
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(board[i][j]==val){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>>&board, int r, int c){
    if(r==9) return true;
    int nextc=c+1,nextr=r;
    if(nextc==9){
        nextr=r+1;
        nextc=0;
    }
    if(board[r][c]!='.'){
        return solve(board,nextr,nextc);
    }
        for(char i='1';i<='9';i++){
            if(isSafe(board,r,c,i)){
                board[r][c]=i;
                if(solve(board,nextr,nextc)){
                    return true;
                }
                board[r][c]='.';
            }   
        }
        return false;
}
int main(){
    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};
     solve(board,0,0);
     for(vector<char>vec:board){
        cout<<"{";
        for(char c:vec){
            cout<<c<<",";
        }
        cout<<"}";
        cout<<"\n";
     }
}