class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.size();
        
        string dominoes=dom;
        vector<bool> vis(n,false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='L' || dominoes[i]=='R'){
                q.push(i);
                vis[i]=true;
            }
        }

        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int ind=q.front();
                q.pop();

                if(dominoes[ind]=='R' && ind+1<n && !vis[ind+1]){
                    if(ind+2>=n ||  dominoes[ind+2]!='L'){
                        dom[ind+1]='R';
                        vis[ind+1]=true;
                        q.emplace(ind+1);
                    }
                }

                if(dominoes[ind]=='L' && ind-1>=0 && !vis[ind-1]){
                    if(ind-2<0 ||  dominoes[ind-2]!='R'){
                        dom[ind-1]='L';
                        vis[ind-1]=true;
                        q.emplace(ind-1);
                    }
                }
                

            }
            dominoes=dom;
        }
        return dom;
    }
};