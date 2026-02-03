#ifndef LEETCODE_TREE_TEMPLATE_H
#define LEETCODE_TREE_TEMPLATE_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/* -------------------------------------------------
   Build tree from level-order (LeetCode style)
   -1 represents null
------------------------------------------------- */

static int i=-1;
TreeNode* buildTreePO(vector<int> preSequence){
  i++;
  if(preSequence[i] == -1) return NULL;

  TreeNode* root = new TreeNode(preSequence[i]);
  root->left = buildTreePO(preSequence);
  root->right = buildTreePO(preSequence);

  return root;
}
/* ---------------- Traversals (for testing) ---------------- */

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

#endif
