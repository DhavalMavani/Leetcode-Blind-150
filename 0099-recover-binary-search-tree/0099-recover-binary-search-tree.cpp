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
    void recover(TreeNode* node,vector<int> &tree, int &i){
        if(node==NULL) return;
        recover(node->left,tree,i);
        node->val=tree[i];
        i++;
        recover(node->right,tree,i);
    }

    void dfs(TreeNode* node,vector<int> &tree){
        if(node==NULL) return;
        dfs(node->left,tree);
        tree.emplace_back(node->val);
        dfs(node->right,tree);
    }
    void recoverTree(TreeNode* root) {
        vector<int> tree;
        dfs(root,tree);
        sort(tree.begin(),tree.end());
        int i=0;
        recover(root,tree,i);

    }
};