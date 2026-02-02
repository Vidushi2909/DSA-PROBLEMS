#ifndef LINKED_LIST_TEMPLATE_H
#define LINKED_LIST_TEMPLATE_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(initializer_list<int> vals) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for(int v : vals) {
        ListNode* node = new ListNode(v);
        if(!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

#endif
