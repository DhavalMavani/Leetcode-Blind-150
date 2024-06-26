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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int sum=INT_MIN,level=1,ans=1;
        while(!q.empty()){
            int n=q.size(),currSum=0;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                currSum+=node->val;
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            if(currSum>sum){
                sum=currSum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};