#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int lower_bound(vector<int>& vec,int tar){
  int n = vec.size();
  int l=0,h=n-1;
  int mid;
  while(l<=h){
    mid = l+(h-l)/2;
    if(vec[mid]<tar){
      l=mid+1;
    }
    else{
      h=mid-1;
    }
  }
  return mid;
}
int main(){
  vector<int> vec ={1,2,4,7,23,45};
  int tar = 9;
  cout<<lower_bound(vec,tar)<<"\n";
}
