#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach=0;
    for(int i=0;i<nums.size();i++){
        if(i>maxReach) return false;
        if(i+nums[i] > maxReach){
            maxReach = i+nums[i];
        }
    }
    return maxReach>=nums.size()-1;
}

int main(){
    vector<int>nums={2,3,1,1,4};
    if(canJump(nums)){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
}