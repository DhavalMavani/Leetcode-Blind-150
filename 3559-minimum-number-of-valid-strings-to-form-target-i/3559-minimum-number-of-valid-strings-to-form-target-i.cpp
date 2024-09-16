class TireNode{
public:
    vector < TireNode* > child;
    TireNode(){
        child.resize(26,NULL);
    }
};

class Tire{
public:
    TireNode* root=new TireNode();

    void insert(string word){
        TireNode* temp = root;
        for(auto &c: word){
            int charNum=c-'a';
            if(temp->child[charNum]==NULL) temp->child[charNum]=new TireNode();
            temp=temp->child[charNum];
        }
    }

};


class Solution {
public:
    string target;
    Tire* root= new Tire();

    int solve(int ind, vector<int> &dp){
        int n=target.size();

        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int ans=1e5;

        TireNode* temp=root->root;

        for(int i=ind;i<n;i++){
            int charNum=target[i]-'a';

            if(temp->child[charNum]==NULL) break;
            temp=temp->child[charNum];
            int res=solve(i+1,dp);
            ans=min(ans,res+1);
        }

        return dp[ind]=ans;
    }
    int minValidStrings(vector<string>& words, string target) {
        this->target=target;
        for(auto &word: words) root->insert(word);

        vector<int> dp(target.size(),-1);
        int ans= solve(0,dp);

        return ans==1e5 ? -1 : ans;
    }
};