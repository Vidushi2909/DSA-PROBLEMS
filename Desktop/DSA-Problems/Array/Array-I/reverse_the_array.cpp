#include<bits/stdc++.h>
using namespace std;


void reverseArray (vector<int> &arr , int m) {
    // Write your code here    
    int n = arr.size();
    if ( m == n-1) return ;
    int low = m+1;
    int high = n-1;
    while(low<=high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }  
    return; 	
}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    int m = 4;
    reverseArray(arr,m);
    for(int val:arr){
        cout<<val<<" ";
    }
}