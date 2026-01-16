#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1== NULL || list2==NULL){
            return list1==NULL? list2:list1;
        }
        if(list1->val <= list2->val){
            list1->next=mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        return list1;
    }

int main(){
    // create linked list
    ListNode* list1= buildList({1, 2, 3, 4, 5});
    ListNode* list2=buildList({1,2,6,7});
    
    ListNode* head = mergeTwoLists(list1,list2);

    cout << "Reversed: ";
    printList(head);

}