#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void allPath(vector<vector<int>>&maze,vector<string>&ans,int row, int col, vector<vector<bool>>&vis, int n,string path){
    if(row<0 || row>=n || col<0 ||col>=n || vis[row][col]==true || maze[row][col]==0){
        return;
    }
    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }

    vis[row][col]=true;
    allPath(maze,ans,row+1,col,vis,n,path+"D");
    allPath(maze,ans,row,col-1,vis,n,path+"L");
    allPath(maze,ans,row,col+1,vis,n,path+"R");
    allPath(maze,ans,row-1,col,vis,n,path+"U");
    vis[row][col]=false;
}
int main(){
    vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>ans;
    int n=maze.size();
    if(maze[0][0]==0 || maze[n-1][n-1]==0){
        cout<<"false";
    }
    string path="";
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    allPath(maze,ans,0,0,vis,n,path);
    //print ans
    for(string str:ans){
        cout<<str<<"\n";
    }
    
}