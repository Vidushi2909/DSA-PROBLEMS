#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int& target) {
        int n = nums.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            int diff = target - nums[i];

            if(m.find(diff) != m.end()){
                return {i,m[diff]};
            }
            m[nums[i]] = i;
        }
        return {};
    }

int main(){
  vector<int> nums ={2,7,11,15};
  int target = 9;
  vector<int>ans = twoSum(nums,target);
  for(int i:ans){
    cout<<i<<" ";
  }
  cout<<"\n";
}