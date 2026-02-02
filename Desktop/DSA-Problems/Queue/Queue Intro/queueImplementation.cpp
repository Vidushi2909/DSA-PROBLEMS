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

class Queue{
  Node* head;
  Node* tail;
  public:
    Queue(){
      head=tail=NULL;
    }

    void push(int val){
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

    void pop(){
      if(head==NULL){
            return;
        }
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;

        delete temp;
    }

    int front(){
      return head->data;
    }

    bool empty(){
      return head==NULL;
    }

};

int main(){
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<"\n";
}