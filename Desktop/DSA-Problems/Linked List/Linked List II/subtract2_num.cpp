#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

int size (ListNode* ll){
  int ans=0;
  ListNode* temp = ll;
  while(temp){
    ans++;
    temp = temp->next;
  }
  return ans;
}


int comp(ListNode* l1, ListNode* l2){
  int length1 = size(l1);
  int length2 = size(l2);

  if(length1 != length2){
    return length1>length2?1:-1;
  }
  
  vector<int>val1(length1);
  vector<int>val2(length2);

  ListNode* temp=l1;
  int idx=0;
  while(temp){
    val1[idx++]=temp->val;
    temp=temp->next;
  }

  temp=l2;
  idx=0;
  while(temp){
    val2[idx++]=temp->val;
    temp=temp->next;
  }

  for(int i=length1 - 1;i>=0;i--){
    if(val1[i]!=val2[i]){
      return (val1[i]>val2[i])?1:-1;
    }
  }
  return 0;
}
  

ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2){
 int comparison = comp(l1,l2);
 if(comparison == 0){
  return new ListNode(0);
 } 

 ListNode* larger=comparison>0?l1:l2;
 ListNode* smaller=comparison>0?l2:l1;

 ListNode* dummy = new ListNode(0);
 ListNode* curr = dummy;

 int borrow = 0;
 while(larger || borrow || smaller){
  int val1 = (larger!=NULL)?larger->val:0;
  int val2=(smaller!=NULL)?smaller->val:0;
  int diff = val1-val2-borrow;

  if(diff < 0){
    diff+=10;
    borrow=1;
  }
  else{
    borrow=0;
  }
  curr->next = new ListNode(diff);
  curr=curr->next;

  if(larger)larger = larger->next;
  if(smaller)smaller=smaller->next;
 }

 ListNode* result=dummy->next;
 ListNode* temp=result;
 ListNode* nonZero=NULL;
 while(temp){
  if(temp->val!=0){
    nonZero=temp;
  }
  temp=temp->next;
 }
 if(nonZero!=NULL){
 nonZero->next = NULL;
 return result;
 }
 else{
  return new ListNode(0);
 }
 return result;
}

void printListt(ListNode*  head){
  ListNode*  temp=head;
  while(temp){
    cout<<temp->val<<"->";
    temp=temp->next;
  }
  cout<<"NULL";
}
int main(){
    ListNode* l1 = buildList({0,1,0});
    ListNode* l2 = buildList({0,9,0});
    ListNode* head=subtractTwoNumbers(l1,l2);
    printListt(head);
}