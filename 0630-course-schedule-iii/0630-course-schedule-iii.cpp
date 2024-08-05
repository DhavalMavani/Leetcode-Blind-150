class Solution {
public:
    static bool comp(const vector<int>& c1, const vector<int>& c2) {
        if (c1[1] != c2[1]) return c1[1] < c2[1];
        return c1[0] < c2[0];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(), courses.end(), comp);

        priority_queue< int> pq;
        // <prev longest duration>
        int time=0;
        for(int i=0;i<n;i++){
            if(time+courses[i][0]<=courses[i][1]){
                pq.emplace(courses[i][0]);
                time+=courses[i][0];
            }
            else if(!pq.empty() && pq.top()>courses[i][0] ){
                time-=pq.top();
                pq.pop();
                pq.emplace(courses[i][0]);
                time+=courses[i][0];
            }
        }

        return pq.size();
    }
};