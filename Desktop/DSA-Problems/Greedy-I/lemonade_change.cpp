#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool lemonadeChange(vector<int>&bill){
    int n=bill.size();
    int five=0,ten=0;
    for(int i=0;i<n;i++){
        if(bill[i]==5){
            five++;
        }
        if(bill[i]==10){
            if(five<=0) return false;
            five--;
            ten++;
        }
        if(bill[i]==20){
            if(five>0 && ten>0){
                five--;ten--;
            }
            else if(five>=3){
                five=five-3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
   vector<int>bill={5,5,10,10,20};
   if(lemonadeChange(bill)){
    cout<<"yes"<<"\n";
   }
   else{
    cout<<"no"<<"\n";
   }
}