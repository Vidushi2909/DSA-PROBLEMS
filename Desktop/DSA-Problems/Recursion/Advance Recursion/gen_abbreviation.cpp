#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solve(string& s, string curr, int idx, int count, vector<string>& ans){

  //base case
  if(idx==s.length()){
    if(count>0) curr+=to_string(count);
    ans.push_back(curr);
    return;
  }
  //skip character
  solve(s,curr,idx+1,count+1,ans);

  //add character
  if(count>0)curr+=to_string(count);
  curr+=s[idx];
  solve(s,curr,idx+1,0,ans);
}

int main(){
  string str="HAT";
  vector<string>ans;
  string curr="";
  solve(str,curr,0,0,ans);
  for(string s:ans){
    cout<<s<<",";
  }
  cout<<"\n";
}