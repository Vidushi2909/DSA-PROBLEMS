#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;

        ListNode* prev=&dummy;
        ListNode* curr=head;

        while(curr){
        if(curr->next && curr->val==curr->next->val){
            int dup=curr->val;
            while(curr && curr->val==dup){
                curr=curr->next;
            }
            prev->next=curr;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        }
        return dummy.next;
    }

int main(){
    ListNode* head=buildList({1,1,2,3,3});
    ListNode* newHead = deleteDuplicates(head);
    printList(newHead);
}