#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>&arr2){
  int m = arr1.size();
  int n = arr2.size();

  vector<int> ans;
  int i=0,j=0;
  while(i<m && j<n){
    if(arr1[i] <= arr2[j]){
      ans.push_back(arr1[i]);
      i++;
    }
    else{
      ans.push_back(arr2[j]);
      j++;
    }
  }

  while(i<m){
    ans.push_back(arr1[i]);
    i++;
  }

  while(j<n){
    ans.push_back(arr2[j]);
    j++;
  }

  return ans;
}
int main(){
  vector<int> arr1 ={1,3,6,8,9};
  vector<int> arr2 ={1,2,4,5,6,7,10};
  vector<int>ans = merge(arr1, arr2);
  for(int val: ans){
    cout<<val<<" ";
  }
  cout<<"\n";
}