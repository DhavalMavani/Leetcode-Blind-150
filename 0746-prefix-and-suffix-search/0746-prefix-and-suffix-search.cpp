class TrieNode{
public:
    vector<int> index;
    unordered_map<string,TrieNode*> child;
};

class Trie{
public:
    TrieNode* root;
    Trie(){ root=new TrieNode(); }

    void insert(string &s,int ind){
        int n=s.size();
        TrieNode* curr=root;

        for(int i=0;i<n;i++){
            string temp = string(1, s[i]) + string(1, s[n-1-i]);
            if(!curr->child.count(temp)) curr->child[temp]=new TrieNode();
            curr=curr->child[temp];
            curr->index.emplace_back(ind);
        }
    }
    int find(string &pref, string &suff){
        int p=pref.size(), s=suff.size(), n=min(p,s);
        TrieNode* curr=root;
        reverse(suff.begin(),suff.end());
        for(int i=0;i<n;i++){
            string temp=string(1,pref[i])+string(1,suff[i]);
            if(!curr->child.count(temp)) return -1;
            curr=curr->child[temp];
        }
        if(p==s) return curr->index.back();
        else if(p>s) return dfs(s,pref,curr,true);
        else return dfs(p,suff,curr,false);

    }

        int dfs(int in,string &word,TrieNode* curr, bool left){
            if(in==word.size()) return curr->index.back();
            int ans=-1;
            for(char i='a';i<='z';i++){
                string temp=word.substr(in,1);
                if(left) temp+=i;
                else temp=i+temp;

                if(curr->child.count(temp)){
                    ans=max(ans,dfs(in+1,word,curr->child[temp], left));
                }
            }
            return ans;
        }

};

class WordFilter {
public:
    Trie* root=new Trie();
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++) root->insert(words[i],i);
    }
    
    int f(string pref, string suff) {
        return root->find(pref,suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */