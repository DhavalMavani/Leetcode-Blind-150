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
    TreeNode* ans=NULL;
    void dfs(TreeNode* node,int key, TreeNode* parents){
        if(node==NULL){
            return;
        }
        if(node->val==key){

            TreeNode* temp=node->left;
                while(temp && temp->right){
                    temp=temp->right;
                }
                if(temp && node->right){
                    temp->right=node->right;
                }else{

                }
                
            if(parents==NULL){
                if(temp){
                    ans=node->left;
                }
                else{
                    ans=node->right;
                }
            }
            else{
                if(temp){
                    if(key < parents->val){
                        parents->left=node->left;
                    }
                    else{
                        parents->right=node->left;
                    }
                }
                else{
                    if(key < parents->val){
                        parents->left=node->right;
                    }
                    else{
                        parents->right=node->right;
                    }
                }
            }
        }
        if(key<node->val){
            dfs(node->left,key,node);
        }
        else{
            dfs(node->right,key,node);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        ans=root;
        dfs(root,key,NULL);
        return ans;
    }
};