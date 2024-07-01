class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // explore all the bus routes 1 by 1 (bfs)
        
        if(source==target) return 0;
        int n=routes.size();
        vector<bool> visited(n,false);

        // bus_stop -> bus_num
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<n;i++){
            for(auto &bus_stop: routes[i]) ump[bus_stop].emplace_back(i);
        }

        queue<int> q;
        for(auto &bus_num: ump[source]){
            if(!visited[bus_num]){
                q.emplace(bus_num);
                visited[bus_num]=true;
            }
        }
        
        int ans=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int bus_num=q.front();
                q.pop();
                for(auto &bus_stop: routes[bus_num]){
                    if(bus_stop==target) return ans;

                    for(auto &new_bus_num: ump[bus_stop]){
                        if(!visited[new_bus_num]){
                            q.emplace(new_bus_num);
                            visited[new_bus_num]=true;
                        }
                    }
                    
                }

            }
            ans++;
            
        }

        return -1;
    }
};