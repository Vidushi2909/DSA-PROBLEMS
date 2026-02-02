#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
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

class circularList{
Node* head;
Node*tail;
public:
  circularList(){
    head=tail=NULL;
  }

  void push_front(int val){
    Node* newNode = new Node(val);
    if(head==NULL){
      head=tail=newNode;
      tail->next=head;
    }
    else{
      newNode->next=head;
      head=newNode;
      tail->next=head;

    }
  }

  void push_back(int val){
    Node* newNode = new Node(val);
    if(tail==NULL){
      head=tail=newNode;
      tail->next=head;
    }
    else{
      newNode->next=head;
      tail->next=newNode;
      tail=newNode;
    }
  }

  void pop_front(){
    if(head==NULL){
      cout<<"List is empty"<<"\n";
      return;
    }
    if(head==tail){
      delete head;
      head=tail=NULL;
    }
    Node* temp=head;
    head=temp->next;
    tail->next=head;

    temp->next=NULL;
    delete temp;
  }

  void pop_back(){
    if(head==NULL){
      cout<<"List is empty"<<"\n";
      return;
    }
     if(head==tail){
      head=tail=NULL;
      delete head;
    }
    Node*  temp=head;
    while(temp->next!=tail){
      temp=temp->next;
    }
    tail=temp;
    temp=temp->next;
    tail->next=head;

    
    delete temp;
  }

  void printList(){
    if(head==NULL) return;
    
    Node* temp=head->next;
    cout<<head->val<<"->";
    while(temp!=head){
      cout<<temp->val<<"->";
      temp=temp->next;
    }
    cout<<"\n";
  }


};

int main(){
    circularList cl;
    cl.push_front(3);
    cl.push_front(2);
    cl.push_front(1);
    cl.push_back(4);
    cl.pop_front();
    cl.pop_back();
    cl.printList();
}