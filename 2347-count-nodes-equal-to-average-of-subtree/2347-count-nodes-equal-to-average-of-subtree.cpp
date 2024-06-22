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

    // size,sum
    pair<int,int> dfs(TreeNode* node){
        if(node==NULL) return {0,0};
        pair<int,int> l=dfs(node->left);
        pair<int,int> r=dfs(node->right);
        int sum=l.second+r.second+node->val, size=l.first+r.first+1;

        if(sum/size ==node->val ) ans++;
        return {size,sum};

    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};