#include<bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int>vec){
    for(int i=0;i<vec.size();i++){
        int small=i;
        for(int j=i+1;j<vec.size();j++){
            if(vec[j]<vec[small]){
               small=j;
            }
        }
        int temp=vec[small];
        vec[small]=vec[i];
        vec[i]=temp;   
    }
    return vec;
}


int main(){
    vector<int>arr = {3,7,5,9,2,8,1};
    vector<int>ans = selection_sort(arr);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<"\n";
}
