class Solution {
public:
    void solve(int index,int &ans,vector<int> &children,vector<int> &cookies){
        if(index==cookies.size()){
            int res=INT_MIN;
            for(auto &i: children) res=max(res,i);
            ans=min(res,ans);
            return;
        }

        for(int i=0;i<children.size();i++){
            children[i]+=cookies[index];
            solve(index+1,ans,children,cookies);
            children[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int> children(k,0);
        solve(0,ans,children,cookies);
        return ans;
    }
};