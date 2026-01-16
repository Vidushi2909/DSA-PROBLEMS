#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int find_pivot(vector<int>& arr){
    int n=arr.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        left[i]=left[i-1]+arr[i];
    }
    for(int i=n-2;i>=0;i--){
        right[i]=right[i+1]+arr[i];
    }
    for(int i=0;i<n;i++){
        if(left[i]==right[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int>arr={1,7,3,6,5,6};
    cout<<find_pivot(arr)<<"\n";
}