/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* node, long sum){
        if(!node) return;
        if(sum==node->val) ans++;

        dfs(node->left,sum-node->val);
        dfs(node->right,sum-node->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};