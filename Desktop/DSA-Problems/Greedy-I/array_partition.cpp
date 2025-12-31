#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int part(vector<int>&nums){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i=i+2){
        sum+=nums[i];
    }
    return sum;

}
int main(){
    vector<int>nums={6,2,6,5,1,2};
    cout<<part(nums)<<"\n";
}