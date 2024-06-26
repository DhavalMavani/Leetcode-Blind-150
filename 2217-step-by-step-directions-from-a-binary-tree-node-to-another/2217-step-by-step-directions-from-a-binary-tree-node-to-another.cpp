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
    bool dfs(TreeNode* node, int &dest,string &s){
        if(!node) return false;
        if(node->val==dest) return true;
        
        // left
        if( dfs(node->left,dest,s) ){
            s+='L';
            return true;
        }

        // right
        if( dfs(node->right,dest,s) ){
            s+='R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string str,des;
        dfs(root,startValue,str);
        dfs(root,destValue,des);
        reverse(str.begin(),str.end());
        reverse(des.begin(),des.end());
        int p1=0,p2=0, s1=str.size(), s2=des.size();

        while(p1<s1 && p2<s2 && str[p1]==des[p2]){
            p1++;
            p2++;
        }
        string ans= string(s1-p1,'U');
        ans.insert(ans.end(),des.begin()+p2,des.end());
        return ans;

    }
};