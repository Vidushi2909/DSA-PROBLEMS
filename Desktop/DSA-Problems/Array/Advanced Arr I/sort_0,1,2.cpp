#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sort_colours(vector<int>& nums){
  int n=nums.size();
  int low =0;
  int high = n-1;
  int mid = 0;
  while(mid<=high){
    if(nums[mid] == 0){
      swap(nums[low],nums[mid]);
      low++;
      mid++;
    }
    else if(nums[mid] == 2){
      swap(nums[mid],nums[high]);
      high--;
    }
    else{
      mid++;
    }
  }
  return ;
}

int main(){
  vector<int> colours = {1,2,0,2,1,0,2,1};
  sort_colours(colours);
  for(int val : colours){
    cout<<val<<" ";
  }
  cout<<"\n";
}