#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

vector<vector<int>> Zig_Zag(TreeNode* root){
  vector<vector<int>>ans;
  deque<TreeNode*>dq;

  bool leftToRight=true;
  if(!root) return ans;
  dq.push_back(root);
  while(!dq.empty()){
  int size=dq.size();
  vector<int>level(size);
  
  for(int i=0;i<size;i++){
    if(leftToRight){
      TreeNode* node = dq.front();
      dq.pop_front();
      level[i] = node->val;

      if(node->left)dq.push_back(node->left);
      if(node->right)dq.push_back(node->right);
    }

    else{
      TreeNode* node = dq.back();
      dq.pop_back();
      level[i]=node->val;

      if(node->right) dq.push_front(node->right);
      if(node->left) dq.push_front(node->left);
    }

  }
  ans.push_back(level);
  leftToRight = !leftToRight;
  }
  return ans;
}
int main(){
  TreeNode* root = buildTree({3,9,20,-1,-1,15,7});
  vector<vector<int>>ans = Zig_Zag(root);
  for(vector<int> vec:ans){
    for(int val:vec){
      cout<<val<<" ";
    }
    cout<<"\n";
  }
}