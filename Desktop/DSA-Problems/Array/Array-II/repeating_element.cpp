#include<bits/stdc++.h>
using namespace std;

vector<int> repeating_element(vector<int>arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    set<int>s;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            s.insert(arr[i]);
        }
    }
    vector<int>ans;
    for(int val:s){
        ans.push_back(val);
    }
    return ans;
}
int main(){
    vector<int>arr={1,1,1,1,2,2,2,3,3,3,4,5,6,7,7,7,8,9,9,9,9};
    vector<int>ans= repeating_element(arr);
    for(int val:ans){
        cout<<val<<" ";
    }
}