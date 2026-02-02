#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> three_sum(vector<int>vec){
  int n = vec.size();
  vector<vector<int>>ans;
  int j,k;
  int sum;
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    if(i>0 && vec[i]==vec[i-1])continue;
    j=i+1,k=n-1;
    while(j<k){
      sum=vec[i]+vec[j]+vec[k];
      if(sum<0){
        j++;
      }
      else if(sum>0){
        k--;
      }
      else{
        ans.push_back({vec[i],vec[j],vec[k]});
        j++;
        k--;
      }
      if(j<k && vec[j] == vec[j-1])j++;
    }
  }
  return ans;
}

int main(){
  vector<int>vec={-1,0,1,2,-1,-4};
  vector<vector<int>>ans=three_sum(vec);
  for(vector<int>vec : ans){
    for(int val:  vec){
      cout<<val<<" ";
    }
    cout<<"\n";
  }
}