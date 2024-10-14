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
    vector<vector<int>> isPossible(TreeNode* node,int target){
        if(node==NULL) return {};
        if(!node->left && !node->right){
            if(target-node->val==0) return {{node->val}};
            return {};
        }
        vector<vector<int>> l=isPossible(node->left,target-node->val);
        vector<vector<int>> r=isPossible(node->right,target-node->val);
        
        for(auto &i: l) i.emplace_back(node->val);
        for(auto &i: r) i.emplace_back(node->val);

        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans=isPossible(root,targetSum);
        for(auto &i: ans) reverse(i.begin(),i.end());
        return ans;
    }
};