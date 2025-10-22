#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
     int maxVal=INT_MIN;
     for(auto p:mp){
        if(p.second > maxVal){
            maxVal= p.second;
        }
     }
     int count =0;
     for(auto p:mp){
        if(p.second == maxVal){
            count++;
        }
     }
     return maxVal*count;
    }
};