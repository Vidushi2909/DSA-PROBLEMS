#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


int count(string& str){
    int count=0;
//    stringstream ss(str);
//    string word;
//    while(ss>>word){
//     count++;
//    }
   bool in_word=false;
   for(char ch:str){
    if(ch!=' '&&!in_word){
        count++;
        in_word=true;
    }
    else if(ch==' '){
        in_word=false;
    }
   }
   return count;
}
int main(){
    string str = "gupta is genius";
    cout<<"no. of words is "<<count(str)<<"\n";
}