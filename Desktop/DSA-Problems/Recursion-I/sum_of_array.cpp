#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int sumArray(vector<int>arr,int i, int sum){
    if(i==arr.size())return sum;
    return sumArray(arr,i+1,sum+arr[i]);
}
int main(){
    vector<int>arr={1,2,3,4};
    cout<<sumArray(arr,0,0)<<"\n";
}