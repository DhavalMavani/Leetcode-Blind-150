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
        if(!node){
            ans+="nb";
            return;
        }
        ans+=to_string(node->val)+'b';
        dfs(node->left,ans);
        dfs(node->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        dfs(root,ans);
        return ans;
    }
    TreeNode* construct(int &i,string &data){
        int str=i;
        while(data[i]!='b') i++;

        string temp=data.substr(str,i-str);
        i+=1;

        if(temp=="n") return NULL;

        TreeNode* ans=new TreeNode(stoi(temp) );
        ans->left=construct(i,data);
        ans->right=construct(i,data);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return construct(i,data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));