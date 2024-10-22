class TrieNode{
public:
    vector<TrieNode*> child;
    bool isWord=false;
    TrieNode(){child.resize(26,NULL);}
};

class Trie{
private:
public:
    TrieNode* root;
    Trie(){root=new TrieNode();}
    void insert(string &word){
        int n=word.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++){
            if(curr->child[word[i]-'a']==NULL) curr->child[word[i]-'a']=new TrieNode();
            curr=curr->child[word[i]-'a'];
        }
        curr->isWord=true;
    }

    bool search(string &word, TrieNode* node, int index){
        int n=word.size();
        TrieNode* curr=node;
        for(int i=index;i<n;i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(curr->child[j]){
                        if(search(word,curr->child[j],i+1)) return true;
                    }
                }
                return false;
            }

            if(curr->child[word[i]-'a']==NULL) return false;
            curr=curr->child[word[i]-'a'];
        } 
        return curr->isWord;
    }
    
    bool find(string &word){ return search(word,root,0); }

};

class WordDictionary {
public:
    Trie* trie;
    WordDictionary() { trie=new Trie(); }
    
    void addWord(string word) { trie->insert(word); }
    
    bool search(string word) { return trie->find(word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */