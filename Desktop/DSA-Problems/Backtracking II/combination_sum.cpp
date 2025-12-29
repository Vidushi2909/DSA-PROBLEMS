#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combination_sum(vector<int>arr, int tar, vector<int>&comb, vector<vector<int>>&ans, int idx){
    if(tar==0){
        ans.push_back(comb);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        if(arr[i]>tar)break;
        comb.push_back(arr[i]);
        combination_sum(arr,tar-arr[i],comb,ans,i);
        comb.pop_back();
    }
}

int main(){
    vector<int>arr={2,3,5};
    int tar=8;
    vector<int>comb;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    combination_sum(arr,tar,comb,ans,0);
    for(vector<int>part:ans){
        cout<<"[";
        for(int val:part){
            cout<<val<<",";
        }
        cout<<"]";
        cout<<",";
    }
}