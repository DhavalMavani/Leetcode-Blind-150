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
    TreeNode *first=NULL,*last=NULL,*prevNode=new TreeNode(INT_MIN);

    void dfs(TreeNode* node){
        if(node==NULL) return;

        dfs(node->left);
        
        if( node->val<prevNode->val){
            if(!first){
                first=prevNode;
                last=node;
            }
            else last=node;
        }
        prevNode=node;

        dfs(node->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val,last->val);
    }
};