#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;


ListNode* ReverseK_groups(ListNode* head, int k){
 
  ListNode* temp=head;
  for(int i=0;i<k;i++){
    if(temp==NULL) return head;
    temp=temp->next;
  }

  ListNode* newNext = ReverseK_groups(temp,k);

  temp=head;
  for(int i=0;i<k;i++){
    ListNode* oldNext = temp->next;
    temp->next=newNext;

    newNext=temp;
    temp=oldNext;
  }
  
  return newNext;

}


int main(){
  ListNode* head = buildList({1,2,3,4,5,6,7,8});
  int k=3;
  printList(ReverseK_groups(head,k));
  
}