#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxArea(vector<int>& height) {
  int n = height.size();
  int l=0,r=n-1;
  int area = 0;
  int h ;
  while(l<=r){
    h = min(height[l],height[r]);
    area  = max(area , (r-l)* h);

    if(height[l] <= height[r]){
      l++;
    }
    else{
      r--;
    }
  }
  return area;
}
int main(){
  vector<int>heights = {1,8,6,2,5,4,8,3,7};
  cout<<maxArea(heights)<<"\n";
}