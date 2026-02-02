#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;

bool isPalindrome(ListNode* head) {
    ListNode *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode* prev=NULL;
    while(slow){
        ListNode* nxt=slow->next;
        slow->next=prev;
        prev=slow;
        slow=nxt;
    }

    while(prev){
        if(prev->val!=head->val) return false;
        prev=prev->next;
        head=head->next;
    }
    return true;
}
