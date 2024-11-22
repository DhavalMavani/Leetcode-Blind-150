class TrieNode{
public:
    TrieNode* left=NULL;
    TrieNode* right=NULL;
};

class Trie{
public:
    TrieNode* root;
    Trie(){root=new TrieNode();}

    void insert(int &num){
        TrieNode* curr=root;

        for(int i=31;i>=0;i--){
            if((num>>i) & 1){
                if(!curr->right) curr->right=new TrieNode();
                curr=curr->right;
            }else{
                if(!curr->left) curr->left=new TrieNode();
                curr=curr->left;
            }
        }
    }

    int maxXOR(int &num){
        TrieNode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            if( (num>>i) & 1){
                if(curr->left){
                    ans+=1<<i;
                    curr=curr->left;
                }
                else curr=curr->right;
            }else{
                if(curr->right){
                    ans+=1<<i;
                    curr=curr->right;
                }
                else curr=curr->left;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        Trie* node=new Trie();
        for(auto &i: nums) node->insert(i);
        for(auto &i: nums) ans=max (ans,node->maxXOR(i));
        return ans;
    }
};