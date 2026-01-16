#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int prod(vector<int>nums){
    if(nums.size()==0) return 0;
    int ans=nums[0];
    int minprod=nums[0];
    int maxprod=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]<0) swap(minprod,maxprod);

        maxprod=max(nums[i],maxprod*nums[i]);
        minprod=min(nums[i],minprod*nums[i]);

        ans=max(ans,maxprod);
    }
    return ans;
}
int main(){
    vector<int>nums={-3,-1,-1,-1};
    cout<<prod(nums)<<"\n";
}
