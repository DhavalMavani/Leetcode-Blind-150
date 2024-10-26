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
    vector<int> depthsum;
    void solve(TreeNode* root, int d){
        if(root==NULL) return;

        if(d>=depthsum.size()) depthsum.emplace_back(root->val);
        else depthsum[d] += root->val;

        solve(root->left, d+1);
        solve(root->right, d+1);
    }
    

    void builtTree(TreeNode* node,int level){

        int childSum=0;
        if(node->left) childSum+=node->left->val;
        if(node->right) childSum+=node->right->val;

        if(node->left){
            node->left->val=depthsum[level+1]-childSum;
            builtTree(node->left,level+1);
        }
        if(node->right){
            node->right->val=depthsum[level+1]-childSum;
            builtTree(node->right,level+1);
        }

    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        solve(root,0);
        root->val=0;
        builtTree(root,0);
        return root;
    }
};