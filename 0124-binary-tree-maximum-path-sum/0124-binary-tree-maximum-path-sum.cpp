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
private:
    int ans=INT_MIN;
    int maxSum(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int l=maxSum(root->left);
        int r=maxSum(root->right);
        if(l>=0 && r>=0){
            ans =max(ans,l+r+root->val);
            return root->val+max(l,r);
        }
        else if(l<0 && r<0){
            ans=max(root->val,ans);
            return root->val;
        }
        else if(l<0){
            ans=max(ans,root->val+r);
            return root->val+r;
        }
        else{
            ans=max(ans,root->val+l);
            return root->val+l;
        }

    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};