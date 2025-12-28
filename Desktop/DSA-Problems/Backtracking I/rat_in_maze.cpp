#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool pathExists(vector<vector<int>>&maze,int row, int col, vector<vector<bool>>&vis, int n,string path){
    if(maze[0][0]==0 || maze[n-1][n-1]==0){
        return false;
    }
    if(row<0 || row>=n || col<0 ||col>=n || vis[row][col]==true || maze[row][col]==0){
        return false;
    }
    if(row==n-1 && col==n-1){
        return true;
    }

    vis[row][col]=true;
    if(pathExists(maze,row+1,col,vis,n,path+"D")) return true;
    if(pathExists(maze,row,col-1,vis,n,path+"L"))return true;
    if(pathExists(maze,row,col+1,vis,n,path+"R"))return true;
    if(pathExists(maze,row-1,col,vis,n,path+"U"))return true;
    vis[row][col]=false;

    return false;
}
int main(){
    // vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<int>>maze={{1,0},{1,0}};
    int n=maze.size();
    string path="";
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    if(pathExists(maze,0,0,vis,n,path)){
        cout<<"yes path exists"<<"\n";
    }
    else{
        cout<<"no path doesn't exist"<<"\n";
    }
}