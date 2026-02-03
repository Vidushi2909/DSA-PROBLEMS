#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
using namespace std;

void postOrder(TreeNode* root){
  if(root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->val<<" ";
}

int main(){
  TreeNode* root = buildTreePO({1,2,-1,-1,3,4,-1,-1,5,-1,-1});
  postOrder(root);
  // vector<int>ans = preorder(root);
  // cout<<"{";
  // for(int val: ans){
  //   cout<<val<<",";
  // }
  // cout<<"}";
  // cout<<"\n";
}
