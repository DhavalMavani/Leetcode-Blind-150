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
    int dfs(TreeNode* node){

        int l=-1,r=-1;
        if(node->left) l=1+dfs(node->left);
        if(node->right) r=1+dfs(node->right);

        if(l==-1 && r==-1) return 1;
        else if(l==-1) return r;
        else if(r==-1) return l;
        else return min(l,r);

    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
};