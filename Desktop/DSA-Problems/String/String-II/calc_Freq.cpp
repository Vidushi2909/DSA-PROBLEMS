#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void calc_freq(string str){
int arr[26];
for(char ch:str){
    arr[ch-'a']++;
}
for(int i=0;i<26;i++){
    if(arr[i]){
        cout<<char('a'+i)<<arr[i]<<" ";
    }
}
cout<<"\n";
}
int main(){
    string str = "takeuforward";
    calc_freq(str);
}