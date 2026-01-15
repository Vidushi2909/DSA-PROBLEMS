#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
};
class MyLinkedList {
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {
        head=tail=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node* temp=head;
        for(int i=0;i<index;i++){
            // if(temp==NULL) return -1;
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next=head;
        head=newNode;
        if(size==0)tail=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            size++;
            return;
        }
       else{
        tail->next=newNode;
        tail=newNode;
       }
       size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index==0){
            addAtHead(val);
            return ;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* temp=head;
        
        for(int i=0;i<index-1;i++){
            // if(temp==NULL) return;
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
    if(index < 0 || index >= size) return;
        if(head!=NULL){
            Node* prev=head;
            if(index==0){
                Node* temp=head;
                head=temp->next;
                temp->next=NULL;
                if(size==1) tail=NULL;
                size--;
                delete temp;
                return;
            }
            for(int i=0;i<index-1;i++){
                prev=prev->next;
            }
            Node* curr =prev->next;
            prev->next=curr->next;
            if(curr == tail) tail=prev;
            delete curr;
            size--;
        }
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(){
    MyLinkedList ll;
    ll.addAtHead(1);
    ll.addAtTail(2);
    ll.addAtHead(3);
    ll.addAtIndex(2,4);
    ll.get(0);
    ll.printList();
}