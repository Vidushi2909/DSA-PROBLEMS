#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"
using namespace std;

class Node{
public:
int val;
Node* prev;
Node* next;
  Node(int data){
    val=data;
    prev=NULL;
    next=NULL;
  }
};

class DoublyList{
  Node* head;
  Node* tail;
  public:
    DoublyList(){
      head=tail=NULL;
    }

    void push_front(int val){
      Node* newNode  = new Node(val);
      if(head==NULL){
        head=tail=newNode;
        return;
      }
      else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
      }
    }

    void push_back(int val){
      Node* newNode= new Node(val);
      if(head==NULL){
        head=tail=newNode;
      }
      else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
      }
    }

    void pop_front(){
      if(head==NULL){
        cout<<"List is empty"<<"\n";
      }
      Node* temp=head;
      head=head->next;
      if(head!=NULL){
        head->prev=NULL;
      }
      temp->prev=NULL;
      delete temp;
    }

    void pop_back(){
      if(head==NULL){
        cout<<"List is empty"<<"\n";
      }
      Node* temp=tail;
      tail = tail->prev;
      if(tail!=NULL){
        tail->next=NULL;
      }

      temp->prev=NULL;
      delete temp;
    }
    void print(){
      Node* temp = head;
      while(temp!=NULL){
        cout<<temp->val<<"<->";
        temp=temp->next;
      }
      cout<<"NULL"<<"\n";
    }
    
};

int main(){
    DoublyList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.pop_front();
    ll.pop_back();
    ll.print();
}