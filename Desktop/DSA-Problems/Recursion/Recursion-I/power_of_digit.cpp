#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long power(int n,int pow){
    if(pow==1)return n;
    if(pow==0)return 1;

    long long half = power(n,pow/2);
    if(pow%2==0){
        return half*half;
    }
    else{
        return n*half*half;
    }
}
int main(){
    int n =5;
    int num=n;
    int pow=0;
    while(num!=0){
        pow=pow*10+num%10;
        num/=10;
    }
    cout<<power(n,pow);
}