#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        if( head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(curr!=NULL && temp!=NULL){
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        return prev;
    }



int main(){
    ListNode* head=buildList({1,2,6,7});
    
    ListNode* newHead = reverseList(head);

    printList(newHead);
}