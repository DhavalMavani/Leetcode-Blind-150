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
    void dfs(TreeNode* &ans,TreeNode* l,TreeNode* r){
        if(!l && !r) return;
        if(!l){
            ans->val=r->val;
            if(r->left){
                ans->left=new TreeNode();
                dfs(ans->left,NULL,r->left);
            }
            if(r->right){
                ans->right=new TreeNode();
                dfs(ans->right,NULL,r->right);
            }
        }
        else if(!r){
            ans->val=l->val;
            if(l->left){
                ans->left=new TreeNode();
                dfs(ans->left,l->left,NULL);
            }
            if(l->right){
                ans->right=new TreeNode();
                dfs(ans->right,l->right,NULL);
            }
        }
        else{
            ans->val=l->val+r->val;
            if(l->left || r->left){
                ans->left=new TreeNode();
                dfs(ans->left,l->left,r->left);
            }
            if(l->right || r->right){
                ans->right=new TreeNode();
                dfs(ans->right,l->right,r->right);
            }
        }

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        TreeNode* ans=new TreeNode();
        dfs(ans,root1,root2);
        return ans;
    }
};