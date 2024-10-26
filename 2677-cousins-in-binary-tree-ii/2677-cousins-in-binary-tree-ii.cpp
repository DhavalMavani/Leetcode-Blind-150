
class Solution {
public:
    vector<int> depthsum;
    
    void solve(TreeNode* root, int d){
        if(root==NULL) return;

        if(d>=depthsum.size()) depthsum.push_back(root->val);
        else depthsum[d] += root->val;

        solve(root->left, d+1);
        solve(root->right, d+1);
    }
    
    // Function to recreate the tree 
    void fill(TreeNode* root, int d){  
        if(root==NULL) return;
        int ded = 0;

        // storing the value of children of current node in ded which to be deducted.
        if(root->left) ded += root->left->val;
        if(root->right) ded += root->right->val;

        // then assigning the sum of all nodes at that depth and subtracting it's own value and the value of its siblings which are stored in ded
        if(root->left) root->left->val = depthsum[d+1] -ded;
        if(root->right) root->right->val = depthsum[d+1] -ded;
        
        // then recursively do the same for all the nodes.
        fill(root->left, d+1);
        fill(root->right, d+1);
        
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) return NULL;
        root->val=0;
        solve(root, 0); // Function to find the depth of each element.
        fill(root, 0); // Function to recreate the tree 
        return root;    
    }
};