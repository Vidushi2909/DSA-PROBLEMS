#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool valid(vector<int>piles, int h, int mid){
  int time =0;
  for(int val:piles){
    if(val<mid) time++;
    else{
      time+=(val/mid)+1;
    }
  }
  return time<=h;
}
int minEatingSpeed(vector<int>piles , int h){
  int low=1;
  int high = INT16_MIN;
  for(int val:piles){
    high = max(high,val);
  }
  int mid;
  while(low<=high){
    mid = low+(high-low)/2;
    if(valid(piles,h,mid)){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return mid;
}
int main(){
  vector<int>piles = {3,6,7,11};
  int h = 8;
  cout<<minEatingSpeed(piles,h);

}