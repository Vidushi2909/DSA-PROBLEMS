#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int count_vowel(string s){
    int count =0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        if(tolower(s[i]) =='a' || tolower(s[i]) =='e' ||  tolower(s[i]) =='i' || tolower(s[i]) =='o' || tolower(s[i]) =='u'){
            count++;
        }
    }
    return count;
}
int count_consonant(string s){
    int count =0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        if(tolower(s[i]) !='a' && tolower(s[i]) !='e' &&  tolower(s[i]) !='i' && tolower(s[i]) !='o' && tolower(s[i]) !='u'){
            count++;
        }
    }
    return count;
}
int main(){
    string s = "tale of the NINE TAILED";
    cout<<"no.of vowels "<<count_vowel(s)<<"\n";
    cout<<"no. of consonants"<<count_consonant(s)<<"\n";
    cout<<"no. of white spaces "<<s.length()-(count_vowel(s)+count_consonant(s))<<"\n";
}