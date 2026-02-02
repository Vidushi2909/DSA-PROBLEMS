#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;
    ListNode*temp=head;
    ListNode* temp1=head->next;
    while(temp1!=NULL){
        if(temp1->val==temp->val){
            temp1=temp1->next;
        }
        else{
            temp->next=temp1;
            temp=temp1;
            temp1=temp->next;
        }
    }
    temp->next=temp1;
    return head;
}

int main(){
    ListNode* head=buildList({1,1,2});
    ListNode* newHead = deleteDuplicates(head);
    printList(newHead);
}