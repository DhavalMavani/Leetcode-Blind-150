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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector <int> ans;
        queue <TreeNode* > q;
        q.emplace(root);
        
        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                if (i==n-1) ans.emplace_back(q.front()->val);

                if(q.front()->left!=NULL) q.emplace(q.front()->left);
                if(q.front()->right!=NULL) q.emplace(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};