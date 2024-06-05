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

    int dfs(TreeNode* node){
        if(node==NULL) return 0;
        
        int l=dfs(node->left);
        int r=dfs(node->right);

        int coins=l+r+node->val-1;
        res+=abs(coins);

        return coins;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};