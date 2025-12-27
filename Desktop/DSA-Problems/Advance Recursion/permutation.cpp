#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void perm(vector<int>&vec,vector<vector<int>>&ans,int idx, int n){
    if(idx>=n){
        ans.push_back(vec);
        return;
    }
    for(int i=idx;i<n;i++){
        swap(vec[i],vec[idx]);
        perm(vec,ans,idx+1,n);
        swap(vec[idx],vec[i]);
    }
}
int main(){
    vector<int>vec={1,2,3};
    vector<vector<int>>ans;
    vector<int>token;
    sort(vec.begin(),vec.end());
    perm(vec,ans,0,vec.size());
    for(vector<int>arr:ans){
        for(int val:arr){
            cout<<val;
        }
        cout<<"\n";
    }
}