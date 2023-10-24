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
    vector<int> validateBSTandSum(TreeNode* node){
        if(!node){
            return {0,INT_MAX,INT_MIN};
        }
        vector <int> l=validateBSTandSum(node->left);
        vector <int> r=validateBSTandSum(node->right);

        if(l[2]<node->val && node->val<r[1]){
            ans= max(node->val+l[0]+r[0], ans );
            return {node->val+l[0]+r[0] , min(l[1], node->val) , max(r[2], node->val) };
        }
        return { max(l[0],r[0]), INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        vector <int> temp;
        temp=validateBSTandSum(root);
        return ans;
    }
};