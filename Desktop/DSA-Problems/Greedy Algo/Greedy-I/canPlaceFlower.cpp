#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int>&flowerBed, int f){
    int count=0;
    int n=flowerBed.size();
   for(int i=0;i<n;i++){
    int left=(i==0)?0:flowerBed[i-1];
    int right=(i==n-1)?0:flowerBed[i+1];
    if(flowerBed[i]==0 && left==0 && right == 0  ){
        flowerBed[i]=1;
        count++;
    }
   }
   return count>=f;
}
int main(){
    vector<int>flowerBed={0,0,1,0,0};
    int n=2;
    if(canPlace(flowerBed,n)){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
}