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


// 0=covered under camera
// 1=camera
// 2=need camera
class Solution {
public:
    int solve(TreeNode* node, int &ans){
        if(node==NULL) return 0;

        int l=solve(node->left,ans);
        int r=solve(node->right,ans);
        
        if(l==2 || r==2){
            ans++;
            return 1;
        }
        else if(l==1 || r==1) return 0;
        else return 2;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(solve(root,ans) ==2) return ans+1;
        return ans;
    }
};