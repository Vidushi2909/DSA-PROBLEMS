#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};

class List{
Node* head;
Node* tail;
   
public:
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        //if lost empty
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        //if list not empty
        else{
            newNode->next=head;
            head=newNode;
        }
    }


    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            tail=newNode;
        }
    }

    void deleteNode(Node* node) {
       node->data= node->next->data;
       node->next=node->next->next;
    }
//for testing in VS CODE
    Node* getNodeAtIndex(int index) {
    Node* temp = head;
    int i = 0;
    while(temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }
    return temp;
}

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

    
};


int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(1);
    ll.push_back(9);
    Node* temp=ll.getNodeAtIndex(1);
    ll.deleteNode(temp);
    ll.printList();
}