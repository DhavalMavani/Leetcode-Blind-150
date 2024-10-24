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
    void isPossible(TreeNode* node,int target, vector<int> &path,vector<vector<int>> &ans){
        if(!node) return;
        if(!node->left && !node->right && node->val==target){
            path.emplace_back(node->val);
            ans.emplace_back(path);
            path.pop_back();
            return;
        }
        path.emplace_back(node->val);
        isPossible(node->left,target-node->val,path,ans);
        isPossible(node->right,target-node->val,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        isPossible(root,targetSum,path,ans);
        return ans;
    }
};