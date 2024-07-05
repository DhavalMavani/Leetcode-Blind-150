/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* node,string &ans){
        ans+=to_string(node->val)+'b';
        if( node->left ) dfs(node->left,ans);
        else ans+='n';

        if( node->right ) dfs(node->right,ans);
        else ans+='n';
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        string ans;
        dfs(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* construct(int &ind,string &data){
        if(data[ind]=='n'){
            ind++;
            return NULL;
        }

        string curr;
        while(data[ind]!='b' ){
            curr+=data[ind];
            ind++;
        }
        ind++;
        TreeNode* node= new TreeNode( stoi(curr) );
        node->left=construct(ind,data);
        node->right=construct(ind,data);
        return node;
    }
    TreeNode* deserialize(string data) {
        int ind=0;
        return construct(ind,data);    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));