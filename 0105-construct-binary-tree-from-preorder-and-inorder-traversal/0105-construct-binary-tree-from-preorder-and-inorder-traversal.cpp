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

// preorder = node , left , right
// inorder = left , node , right
class Solution {
public:
    unordered_map<int,int> inorderHash;
    TreeNode* build(int pl,int pr,int il,int ir,vector<int>& preorder, vector<int>& inorder){
        if(pl>pr || il>ir) return NULL;
        int ind=inorderHash[preorder[pl]],numsOnleft=ind-il;
        TreeNode* curr=new TreeNode(preorder[pl],build( pl+1,pl+numsOnleft, il,ind-1  ,preorder,inorder),build( pl+numsOnleft+1, pr, ind+1,ir  ,preorder,inorder));
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++) inorderHash[inorder[i]]=i;
        return build(0,n-1,0,n-1,preorder,inorder);
    }
};