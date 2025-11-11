#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> vec){
    int key,i,j;
    for(int i=1;i<vec.size();i++){
       key=vec[i]; 
       j=i-1;
       while(j>=0 && vec[j]>key){
        vec[j+1]=vec[j];
        j--;
       }
       vec[j+1]=key;
    }
    return vec;
}
int main(){
    vector<int>arr = {3,8,1,9,5,0,6};
    vector<int>ans = insertion_sort(arr);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<"\n";
}
