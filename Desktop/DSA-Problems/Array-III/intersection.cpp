#include<bits/stdc++.h>
using namespace std;

vector<int> unionArray (vector<int>nums1 ,vector<int>nums2){
    set<int>s;
    for(int i=0;i<nums1.size();i++){
        s.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
        s.insert(nums2[i]);
    }
    vector<int>ans(s.size());
    for(int val:s){
        ans.push_back(val);
    }
    return ans;
}

vector<int> intersectionArray (vector<int>nums1 ,vector<int>nums2){
    if(nums2.size()<nums1.size()) swap(nums1,nums2);
    int m=nums1.size(),n=nums2.size();
    vector<int>ans(m);
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.begin());
    int i,j=0;
    while(i<nums1.size() || j<nums2.size()){
        if(nums1[i]==nums2[j]){
            ans.push_back(nums1[i]);
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>arr1 = { 1,2,4,5,6};
    vector<int>arr2 = {3,5,8,9};
    vector<int>unionarr=unionArray(arr1,arr2);
    vector<int>intersectionarr= intersectionArray(arr1,arr2);
    for(int val:unionarr){
        cout<<val<<" ";
    }
    cout<<"\n";
    for(int val:intersectionarr){
        cout<<val<<" ";
    }
    cout<<"\n";
}