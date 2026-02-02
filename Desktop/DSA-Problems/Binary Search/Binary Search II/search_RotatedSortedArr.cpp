#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int search(vector<int>nums,int tar){
  int n=nums.size();
  int l=0,h=n-1;
  int mid;
  while(l<=h){
    mid = l+(h-l)/2;

    if(nums[mid] == tar){
      return mid;
    }
    else if(nums[l] <=nums[mid]){//left sorted
      if(nums[l]<=tar && tar<=nums[mid]){
        h=mid-1;
      }
      else{
        l=mid+1;
      }
    }
    else{//right sorted
      if(nums[mid]<=tar && tar<=nums[h]){
        l=mid+1;
      }
      else{
        h=mid-1;
      }
    }
  }
  return -1;
}
int main(){
  vector<int>nums = {4,5,6,7,0,1,2};
  int target = 7;
  cout<<search(nums,target)<<"\n";
}