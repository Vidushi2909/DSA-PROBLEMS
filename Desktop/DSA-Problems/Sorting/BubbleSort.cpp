#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& vec){
    int n=vec.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(vec[j]>vec[j+1]){
                int temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
    
}
int main(){
    vector<int>arr = {3,7,5,9,2,8,1};
    bubble_sort(arr);
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<"\n";
}
