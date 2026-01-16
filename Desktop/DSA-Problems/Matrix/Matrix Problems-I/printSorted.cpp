#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>&arr, int st, int mid, int end){
    vector<int>result;
    int i=st,j=mid+1;
    while(i<=mid &&  j<=end){
        if(arr[i]<=arr[j]){
            result.push_back(arr[i]);
            i++;
        }
        else{
            result.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        result.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        result.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<result.size();i++){
        arr[i+st]=result[i];
    }
}
void mergeSort(vector<int>&arr,int st, int end){
    if(st==end){
        return;
    }
    int mid=st+(end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
}
vector<int> sortedArray(vector<int>&arr){
    int st=0;
    int end=arr.size()-1;
    mergeSort(arr,st,end);
    return arr;
}
int main(){
    vector<int>arr={5,2,7,1,0,6,0,4};
    sortedArray(arr);
    for(int val:arr){
        cout<<val<<",";
    }
    cout<<"\n";
}