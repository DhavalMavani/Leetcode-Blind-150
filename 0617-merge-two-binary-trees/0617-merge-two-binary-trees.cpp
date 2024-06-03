class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If both nodes exist, add their values then look at the next node.
        if(root1!=NULL && root2!=NULL){
            root1->val += root2->val;
            root1->left=mergeTrees(root1->left,root2->left);
            root1->right=mergeTrees(root1->right,root2->right);
        }else{//If one node doesn't exist,NOT null node will be used.
            return root1? root1: root2;
        }
        //Return the first tree, which is now altered. No need to create a new node, which bloats memory.
        return root1;
    }
};