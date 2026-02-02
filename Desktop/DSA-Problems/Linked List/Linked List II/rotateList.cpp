#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* curr=head;
    ListNode* last=NULL;
    int count=0;
    while(curr){
        count++;
        if(curr->next==NULL) last=curr;
        curr=curr->next;
        
    }
    curr=head;
    int rotations=count-(k%count);
    ListNode* prev=NULL;
    while(rotations){
        prev=curr;
        curr=curr->next;
        rotations--;
    }
    last->next=head;
    prev->next=NULL;

    return curr;
}
int main(){
    ListNode* head=buildList({0,1,2});
    int k=4;
    ListNode* newHead = rotateRight(head,k);
    printList(newHead);
}