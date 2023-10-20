/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:

    vector<TreeNode*> findPath(TreeNode* node,TreeNode* target){
        if(node==NULL){
            return {NULL};
        }
        if(node==target){
            return {node};
        }

        vector<TreeNode*> v1=findPath(node->left,target);
        v1.emplace_back(node);
        if(v1[0]){
            return v1;
        }
        vector<TreeNode*> v2=findPath(node->right,target);
        v2.emplace_back(node);

        return v2;
    };


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> routeP;
        vector<TreeNode*> routeQ;
        routeP=findPath(root,p);
        routeQ=findPath(root,q);
        reverse(routeP.begin(),routeP.end());
        reverse(routeQ.begin(),routeQ.end());
        int n=min(routeP.size(),routeQ.size());

        TreeNode* ans=root;
        for(int i=0;i<n;i++){
            if(routeP[i]!=routeQ[i]){
                break;
            }
            ans=routeP[i];
        }
        return ans;
    }
};