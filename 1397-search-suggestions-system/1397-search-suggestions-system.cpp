class TrieNode{
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode(){
        child.resize(26,NULL);
        isWord=false;
    }
};

class Trie{
public:
    TrieNode* node;
    Trie(){ node=new TrieNode(); }

    void insert(string &s){
        TrieNode* curr=node;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(curr->child[s[i]-'a']==NULL ) curr->child[s[i]-'a']=new TrieNode();
            curr=curr->child[s[i]-'a'];
        }
        curr->isWord=true;
    }

    vector<string> search(string &s){
        TrieNode* curr=node;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(curr->child[s[i]-'a']==NULL ) return {};
            curr=curr->child[s[i]-'a'];
        }
        vector<string> res;
        dfs(curr,res,"");
        for(auto &i: res) i=s+i;
        return res;
    }

    void dfs(TrieNode* curr,vector<string> &res,string s){
        if(res.size()==3) return;
        if(curr->isWord) res.emplace_back(s);

        for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL){
                dfs(curr->child[i],res,s+char('a'+i));
            }
        }
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root=new Trie();
        for(auto &product: products) root->insert(product);
        vector<vector<string>> ans;
        int n=searchWord.size();

        string str;
        for(auto &i: searchWord){
            str+=i;
            ans.emplace_back(root->search(str));
        }
        return ans;
    }
};