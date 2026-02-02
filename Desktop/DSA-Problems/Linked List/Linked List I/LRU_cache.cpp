#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<algorithm>
#include "C:\Users\Vidushi\Desktop\DSA-Problems\Linked List\Template\linked_list_template.h"

using namespace std;

class LRUCache {
public:
class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
    };
   
    unordered_map<int,Node*>m;
    int limit;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        limit=capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newNode){

        Node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
        }

    void deleteNode(Node* temp){
        Node* oldPrev = temp->prev;
        Node* oldNext = temp->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }

    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        deleteNode(ansNode);

        m[key]=ansNode;
        addNode(ansNode);

        return ans;

    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            m.erase(key);
            deleteNode(node);
        }

        if(m.size()==limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key,val);
        addNode(newNode);
        m[key]=newNode;
        
    }
  };
int main(){
  LRUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl;

    cache.put(3,3);              
    cout << cache.get(2) << endl;

    cache.put(4,4);              
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}