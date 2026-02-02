#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

class Stack{
 list<int>ll;

 public:
   void push(int val){
    ll.push_front(val);
   }

   void pop(){
    ll.pop_front();
   }

   int top(){
    ll.front();
   }

   bool empty(){
    return ll.empty();
   }
};
int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  cout<<s.top()<<"\n";
}