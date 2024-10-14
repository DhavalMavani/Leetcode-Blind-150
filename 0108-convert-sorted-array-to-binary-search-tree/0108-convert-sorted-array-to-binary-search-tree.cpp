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
    TreeNode* build(int l,int r,vector<int>& nums){
        if(l>r) return NULL;

        int mid=(l+r)/2;
        TreeNode* t=new TreeNode(nums[mid]);
        t->left=build(l,mid-1,nums);
        t->right=build(mid+1,r,nums);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0,nums.size()-1,nums);
    }
};