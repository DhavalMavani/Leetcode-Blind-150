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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.emplace(root);

        while(true){
            if(st.top()==NULL){
                if(st.size()==1) return ans;
                st.pop();
                ans.emplace_back(st.top()->val);
                auto t=st.top()->right;
                st.pop();
                st.emplace(t);
            }
            else {
                st.emplace(st.top()->left);
            }
        }
        return {};
    }
};