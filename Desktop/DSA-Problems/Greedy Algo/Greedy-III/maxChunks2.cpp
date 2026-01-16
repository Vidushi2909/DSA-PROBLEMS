// You are given an integer array arr.
// We split arr into some number of chunks (i.e., partitions), and individually sort each
// chunk. After concatenating them, the result should equal the sorted array.
// Return the largest number of chunks we can make to sort the array.
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>leftMax(n,0);
        vector<int>rightMin(n,0);
        //leftMax
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(arr[i],leftMax[i-1]);
        }
        //rightMin
        rightMin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMin[i]=min(rightMin[i+1],arr[i]);
        }
        int chunks=1;
        for(int i=0;i<n-1;i++){
            if(leftMax[i]<=rightMin[i+1]){
                chunks++;
            }
        }
        return chunks;
    }

int main(){
    vector<int>vec={2,1,3,4,4};
    cout<<maxChunksToSorted(vec)<<"\n";
}