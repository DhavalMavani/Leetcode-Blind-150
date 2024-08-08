class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);

        unordered_map<int, vector<pair<int,bool>> > ump;

        for(auto &i: redEdges) ump[i[0]].push_back( {i[1],false} );
        for(auto &i: blueEdges) ump[i[0]].push_back( {i[1],true} );


        vector<vector<bool>> visited(n, vector<bool>(2, false)); // Visited array (node, color)

        visited[0][0]=true;
        visited[0][1]=true;

        ans[0]=0;
        queue< pair<int,bool> > q;
        q.push({0,false});
        q.push({0,true});

        // node, prev colour
        // false -> red, true -> blue

        int dist=1;
        while(!q.empty()){
            int s=q.size();
            for(int j=0;j<s;j++){
                int node=q.front().first;
                bool colour=q.front().second;
                q.pop();
                for(auto &i: ump[node]){
                    if(colour != i.second && !visited[i.first][!colour]){
                        if(ans[i.first]==-1)  ans[i.first]=dist;
                        q.push({i.first,i.second});
                        visited[i.first][!colour]=true;
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};