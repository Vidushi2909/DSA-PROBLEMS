#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> slidingWindowMax(vector<int>vec, int k){
  int n=vec.size();
  vector<int>ans;
  deque<int>dq;
  
  for(int i=0;i<k;i++){
    while(dq.size() >0 && vec[dq.back()]<vec[i]){
      dq.pop_back();
    }
    dq.push_back(i);
  }

  for(int i=k;i<n;i++){
    ans.push_back(vec[dq.front()]);

    //remove elements not of curr window
    while(dq.size() && dq.front()<=i-k){
      dq.pop_front();
    }

    //remove elements fron  front which are smaller than current val
    while(dq.size() && vec[dq.back()]<vec[i]){
      dq.pop_back();
    }
    
    dq.push_back(i);
  }
  ans.push_back(vec[dq.front()]);
  return ans;
}

int main(){
  vector<int>vec={1,3,-1,-3,5,3,6,7};
  int k=3;
  vector<int>ans = slidingWindowMax(vec,k);
  for(int i:ans){
    cout<<i<<" ";
  }
  cout<<"\n";
}