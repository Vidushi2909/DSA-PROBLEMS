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

    int getCount(Node* head) {
        
        Node* temp=head;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        return length;
    }

    //for testing
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
    Node* head=ll.getNodeAtIndex(0);
    cout<<ll.getCount(head)<<"\n";
}