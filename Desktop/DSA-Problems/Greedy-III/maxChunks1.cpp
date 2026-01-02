// You are given an integer array arr of length n that represents a permutation of the integer
// s in the range [0, n - 1].
// We split arr into some number of chunks (i.e., partitions), and individually sort each
//  chunk. After concatenating them, the result should equal the sorted array.
// Return the largest number of chunks we can make to sort the array.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
        int maxChunks=0;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            maxChunks=max(maxChunks,arr[i]);
            if(maxChunks==i){
                chunks++;
            }
        }
    return chunks;
}

int main(){
    vector<int>arr={4,3,2,1,0};
    cout<<maxChunksToSorted(arr)<<"\n";
}
 