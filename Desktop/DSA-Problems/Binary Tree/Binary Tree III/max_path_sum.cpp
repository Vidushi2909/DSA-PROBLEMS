#include<iostream>
#include<C:\Users\Vidushi\Desktop\DSA-Problems\Binary Tree\Template\Template.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int maxSum = INT_MIN;

int dfs(TreeNode* root) {
    if(!root) return 0;
    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));
    maxSum = max(maxSum, root->val + left + right);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return maxSum;
}
