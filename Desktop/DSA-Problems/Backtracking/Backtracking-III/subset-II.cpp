#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void subsets(vector<int>&nums,vector<vector<int>>&ans,vector<int>&token, int idx, int& n){
    ans.push_back(token);
    for(int i=idx;i<n;i++){
    if(i>idx && nums[i]==nums[i-1]) continue;
    token.push_back(nums[i]);
    subsets(nums,ans,token,i+1,n);
    token.pop_back();
    }
}

int main(){
    vector<int>nums={1,2,2};
    vector<vector<int>>ans;
    vector<int>token;
    int n=nums.size();
    subsets(nums,ans,token,0,n);
    for(vector<int>vec:ans){
        cout<<"[";
        for(int val:vec){
            cout<<val<<",";
        }
        cout<<"]";
        cout<<"\n";
    }
}