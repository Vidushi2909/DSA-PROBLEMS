#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
using namespace std;

void inOrder(TreeNode* root){
  if(root == NULL) return;
  inOrder(root->left);
  cout<<root->val<<" ";
  inOrder(root->right);
  
}

int main(){
  TreeNode* root = buildTreePO({1,2,-1,-1,3,4,-1,-1,5,-1,-1});
  inOrder(root);
  // vector<int>ans = preorder(root);
  // cout<<"{";
  // for(int val: ans){
  //   cout<<val<<",";
  // }
  // cout<<"}";
  // cout<<"\n";
}
