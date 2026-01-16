#include<bits/stdc++.h>
using namespace std;

//linear search
int lin_search(vector<int>arr,int n,int tar){
    for(int i=0;i<n;i++){
        if(arr[i]==tar){
            return i;
        }
    }
    return -1;
}
//binary search
int bin_search(vector<int>arr,int n,int tar){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<tar){
            low=mid+1;
        }
        else if(arr[mid]>tar){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
//fibonacci search
int fib_search(vector<int>arr,int n,int tar){
    int fibM=1;
    int fibM_1=1;
    int fibM_2=0;
    while(fibM<n){
        fibM_2=fibM_1;
        fibM_1=fibM;
        fibM=fibM_1+fibM_2;
    }
    int offset=-1;
    while(fibM>1){
        int i=min(offset+fibM_2,n-1);
        if(arr[i]<tar){
            fibM=fibM_1;
            fibM_1=fibM_2;
            fibM_2=fibM-fibM_1;
            offset=i;
        }
        else if(arr[i]>tar){
            fibM=fibM_2;
            fibM_1=fibM_1-fibM_2;
            fibM_2=fibM-fibM_1;
        }
        else{
            return i;
        }
    }
    if(fibM_1 && arr[offset+1]==tar){
        return offset+1;
    }
    return -1;
}
int main(){
    vector<int>arr={1,6,4,8,2,9,3,8};
    int tar=9;
    cout<<"target found at "<<lin_search(arr,arr.size(),tar)<<"\n";

    cout<<"target found at "<<bin_search(arr,arr.size(),tar)<<"\n";
    cout<<"target found at "<<fib_search(arr,arr.size(),tar)<<"\n";
}