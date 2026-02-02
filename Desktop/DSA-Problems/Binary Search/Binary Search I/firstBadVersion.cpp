#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int badVersion ;

bool isBad(int version) {
    return version >= badVersion;
}

int firstBadVersion(int n){
  int low=1;
  int high = n;
  int mid,ans=-1;
  while(low<=high){
    int mid = low+(high-low)/2;
    if(isBad(mid)){
      ans=mid;
      high=mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return ans;
}

int main(){
 int n = 8;
 badVersion = 4;
 cout<<firstBadVersion(n)<<"\n";
}