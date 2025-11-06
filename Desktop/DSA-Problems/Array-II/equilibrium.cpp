#include<bits/stdc++.h>
using namespace std;

int equilibrium(vector<int>arr){
    int n=arr.size();
    int total=0;
    for(int val:arr){
        total+=val;
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        if(2*leftsum==total-arr[i]){
            return i;
        }
        leftsum+=arr[i];
    }
    return -1;
}

int main(){
    vector<int>vec={2,1,-1};
    cout<<equilibrium(vec)<<"\n";
}