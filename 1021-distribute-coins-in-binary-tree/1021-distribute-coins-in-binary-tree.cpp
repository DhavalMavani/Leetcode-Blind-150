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
    int res=0;

    pair<int,int> dfs(TreeNode* node){
        if(node==NULL) return {0,0};
        
        pair<int,int> l=dfs(node->left);
        pair<int,int> r=dfs(node->right);
        
        int s=l.first+r.first+1, coins=l.second+r.second+node->val;
        res+=abs(coins-s);

        return {s,coins};
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};