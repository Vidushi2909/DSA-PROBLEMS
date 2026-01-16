#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxSubArr(vector<int>nums){
    int sum=0;
    int maxsum=INT32_MIN;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        maxsum=max(sum,maxsum);
        if(sum<0){
            sum=0;
        }
    }
    return sum;
}
int main(){
    vector<int>nums={5,4,-1,7,8};
    cout<<maxSubArr(nums)<<"\n";
}
