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
    bool isValidBST(TreeNode* root,pair<long,long> range={LONG_MIN,LONG_MAX}) {
        if(root==NULL) return true;
        
        bool l=isValidBST(root->left,{range.first,root->val});
        bool r=isValidBST(root->right,{root->val,range.second});

        if(range.first<root->val && root->val<range.second) return l && r;
        else return false;
    }
};