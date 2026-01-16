#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsets(vector<int>arr,vector<vector<int>>&ans,vector<int>&token,int idx, int n){
    ans.push_back(token);

    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1]) continue;
        token.push_back(arr[i]);
        subsets(arr,ans,token,i+1,n);
        token.pop_back();
    }
}
int main(){
    vector<int>vec={1,2,2};
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