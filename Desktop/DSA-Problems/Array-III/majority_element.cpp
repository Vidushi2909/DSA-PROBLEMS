#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int majority(vector<int>& nums) {
        int num=0;
        int count=0;
        for(int val : nums){
            if(count==0){
                num=val;
            }
            count+=((val==num)?1:-1);
        }
        return num;
    }
int main(){
    vector<int>nums={6,5,5};
    cout<<majority(nums)<<"\n";
}

