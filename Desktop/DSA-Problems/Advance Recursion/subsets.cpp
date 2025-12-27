#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsets(vector<int>vec,vector<vector<int>>&ans,vector<int>&token,int i, int n){
    if(i>=n){
        ans.push_back(token);
        return;
    }
    token.push_back(vec[i]);
    subsets(vec,ans,token,i+1,n);
    token.pop_back();
    subsets(vec,ans,token,i+1,n);
}
int main(){
    vector<int>vec={1,2,3};
    vector<vector<int>>ans;
    vector<int>token;
    subsets(vec,ans,token,0,vec.size());
    for(vector<int>arr:ans){
        for(int val:arr){
            cout<<val;
        }
        cout<<"\n";
    }
}