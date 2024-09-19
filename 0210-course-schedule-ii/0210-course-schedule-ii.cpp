class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses,0);

        for(auto &i: prerequisites){
            graph[i[1]].emplace_back(i[0]);
            inDegree[i[0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]){
                ans.emplace_back(i);
                q.emplace(i);
            }    
        } 

        while(!q.empty()){
            int c=q.front();
            q.pop();

            for(auto &i: graph[c]){
                inDegree[i]--;
                if( !inDegree[i] ){
                    ans.emplace_back(i);
                    q.emplace(i);
                }
            }
        }

        if(ans.size()==numCourses) return ans;
        return {};
    }
};