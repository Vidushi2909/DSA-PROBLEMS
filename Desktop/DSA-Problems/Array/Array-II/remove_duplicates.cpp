#include<bits/stdc++.h>
using namespace std;

int remove_Duplicates(vector<int>& arr){
    int n=arr.size();
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[j]){
            arr[j+1]=arr[i];
            j++;
        }
    }
    return j+1;
}
int main(){
    vector<int>arr={8,8,8,7,7,6,6,4,4,3,2,2,1};
    int k=remove_Duplicates(arr);
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}