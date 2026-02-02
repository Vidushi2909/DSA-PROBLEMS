#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

ListNode* helper(ListNode* l1, ListNode* l2,int carry) {
    if(!l1 && !l2 && carry==0){
        return NULL;
    }
    int sum=carry;
    if(l1)sum+=l1->val;
    if(l2)sum+=l2->val;

    ListNode* node= new ListNode(sum%10);
    node->next=helper(
        l1?l1->next:NULL, l2?l2->next:NULL, sum/10
    );
    return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   return helper(l1,l2,0);
}
int main(){
    ListNode* l1 = buildList({2,4,3});
    ListNode* l2 = buildList({5,6,4});
    ListNode* head=addTwoNumbers(l1,l2);
    printList(head);
}