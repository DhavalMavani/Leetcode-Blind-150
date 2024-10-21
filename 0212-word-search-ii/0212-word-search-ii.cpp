class tireNode{
public:
    bool isWord=false;
    tireNode* child[26]={NULL};
};

class Solution {
public:
    tireNode* root=new tireNode();
    vector <string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &i: words) insert(i);

        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                string s="";
                dfs(i,j,board,s,root);
            }
        }
        return ans;
    }

    void dfs(int r, int c,vector<vector<char>>& board,string s,tireNode* curr){

        if(curr->isWord){
            ans.emplace_back(s);
            curr->isWord = false;
        }

        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='#' || curr->child[board[r][c]-'a']==NULL ) return;

        char temp= board[r][c];
        board[r][c]='#';
        dfs(r+1,c,board,s+temp,curr->child[temp-'a']);
        dfs(r,c+1,board,s+temp,curr->child[temp-'a']);
        dfs(r-1,c,board,s+temp,curr->child[temp-'a']);
        dfs(r,c-1,board,s+temp,curr->child[temp-'a']);
        board[r][c]=temp;

    }
    void insert(string &word){
        tireNode* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->child[word[i]-'a']==NULL){
                tireNode* temp=new tireNode();
                curr->child[word[i]-'a']=temp;
            }
            curr=curr->child[word[i]-'a'];
        }
        curr->isWord=true;
    }
};