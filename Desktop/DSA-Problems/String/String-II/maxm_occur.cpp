#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char maxm_occurence(string str){
int arr[26]={0};
for(char ch:str){
    arr[ch-'a']++;
}
int maxm=INT32_MIN;
char ch;
for(int i=0;i<26;i++){
    if(arr[i] && arr[i] > maxm){
       maxm=arr[i];
       ch=char('a'+i);
    }
}
return ch;
}
int main(){
    string str = "gupta";
    cout<<maxm_occurence(str)<<"\n";
}