#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int diameter = 0;

int height(TreeNode* root) {
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    height(root);
    return diameter;
}

int main(){
  TreeNode* root = buildTree({3,9,20,-1,-1,15,7});
  int h= height(root);
  cout<<h<<"\n";
}