#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
      val=data;
      left=right=NULL;
    }
};
static int i=-1;
Node* buildTree(vector<int> preSequence){
  i++;
  if(preSequence[i] == -1) return NULL;

  Node* root = new Node(preSequence[i]);
  root->left = buildTree(preSequence);
  root->right = buildTree(preSequence);

  return root;
}

int main(){
  vector<int> arr  = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root = buildTree(arr);
  cout<<root->val<<" ";
  cout<<root->left->val<<" ";
  cout<<root->right->val<<" ";
  cout<<"\n";
}