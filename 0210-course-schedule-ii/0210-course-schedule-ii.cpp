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

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int currNode=q.front();
            q.pop();

            ans.emplace_back(currNode);

            for(auto &i: graph[currNode]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }

        }

        if(ans.size()==numCourses) return ans;

        return {};
    }
};