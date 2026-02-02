#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast=&dummy, *slow=&dummy;

    for(int i=0;i<=n;i++) fast=fast->next;
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
}
