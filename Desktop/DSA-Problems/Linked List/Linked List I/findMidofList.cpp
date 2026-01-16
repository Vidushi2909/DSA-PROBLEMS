#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }


int main(){
    ListNode* head=buildList({1,2,6,7});
    
    ListNode* newHead = middleNode(head);

    printList(newHead);
}