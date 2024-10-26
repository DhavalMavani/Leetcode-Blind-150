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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int levelSum=-root->val;
        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()){
            int n=q.size();
            int nextLevelSum=0;
            while(n--){
                TreeNode* currNode=q.front();
                q.pop();

                currNode->val+=levelSum;
                
                int childSum=0;
                if(currNode->left){
                    nextLevelSum+=currNode->left->val;
                    childSum+=currNode->left->val;
                    q.emplace(currNode->left);
                }
                if(currNode->right){
                    nextLevelSum+=currNode->right->val;
                    childSum+=currNode->right->val;
                    q.emplace(currNode->right);
                }
                if(currNode->left) currNode->left->val=-childSum;
                if(currNode->right) currNode->right->val=-childSum;
            }
            levelSum=nextLevelSum;
        }

        return root;
    }
};