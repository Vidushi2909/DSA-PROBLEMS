#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int minPlatform(vector<int>&arr, vector<int>&dep){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int platforms=0;
    int maxplatforms=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            platforms++;
            maxplatforms=max(maxplatforms,platforms);
            i++;
        }
        else{
            platforms--;
            j++;
        }
    }
    return maxplatforms;
}
int main(){
    vector<int>arr={900, 940, 950, 1100, 1500, 1800};
    vector<int>dep={910, 1200, 1120, 1130, 1900, 2000};
    cout<<minPlatform(arr,dep)<<"\n";
}