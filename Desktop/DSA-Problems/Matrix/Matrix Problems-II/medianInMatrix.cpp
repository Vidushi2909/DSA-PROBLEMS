#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<vector<int>>&mat, vector<int>&result,int r){
    int m=mat.size();
    int n=mat[0].size();
    int k=result.size();
    int i=0,j=0;
    vector<int>temp;
    while(i<k && j<n){
        if(mat[r][j]<=result[i]){
            temp.push_back(mat[r][j]);
            j++;
        }
        else{
            temp.push_back(result[i]);
            i++;
        }
    }
    while(i<k){
        temp.push_back(result[i]);
        i++;
    }
    while(j<n){
        temp.push_back(mat[r][j]);
        j++;
    }
    result=temp;
}
int median(vector<vector<int>>&mat){
    vector<int>result;
    int m=mat.size();
    int n=mat[0].size();
    for(int i=0;i<n;i++){
        result.push_back(mat[0][i]);
    }
    for(int i=1;i<m;i++){
        merge(mat,result,i);
    }
    int mid=0+(result.size()-1)/2;
    return result[mid];

}
int  main(){
    vector<vector<int>>mat={{1,3,5},{2,6,9},{3,6,9}};
    cout<<median(mat)<<"\n";
}