class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> ans;
        priority_queue<p, vector<p> , greater<p> > pq;
        set<pair<int,int>> st;
        st.insert({0,0} );
        pq.push({nums1[0]+nums2[0],{0,0} });

        while(k--){
            p curr= pq.top();
            pq.pop();
            auto [i1,i2]=curr.second;
            ans.push_back({nums1[i1],nums2[i2]});

            if(i2+1<n2 && !st.count({i1,i2+1}) ){
                pq.push({nums1[i1] +nums2[i2+1],{i1,i2+1} });
                st.insert({i1,i2+1});
            } 
                
            if(i1+1<n1 && !st.count({i1+1,i2})){
                pq.push({nums1[i1+1] +nums2[i2],{i1+1,i2} });
                st.insert({i1+1,i2});
            }
        }
        return ans;
    }
};




