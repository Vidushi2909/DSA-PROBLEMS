#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

vector<vector<int>> level_Order(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
  TreeNode* root = buildTree({3,9,20,-1,-1,15,7});
  vector<vector<int>>ans = level_Order(root);
  for(vector<int> vec:ans){
    for(int val:vec){
      cout<<val<<" ";
    }
    cout<<"\n";
  }
}