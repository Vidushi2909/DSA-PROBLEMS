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

    bool searchMTF(int val){
        if(head == NULL) return false;
        if(head->data==val) return true;

        Node* prev=head;
        Node* curr=head->next;
        bool found=false;
        while(curr!=NULL){
            if(curr->data==val){
                found=true;
            if(prev!=NULL){
            prev->next=curr->next;
            curr->next=head;
            head=curr;
        }
                break;
            }
            prev=curr;
            curr=curr->next;
        }
        
        return found;
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
    cout<<ll.searchMTF(5)<<"\n";
    cout<<ll.searchMTF(8)<<"\n";

}