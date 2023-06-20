class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map <int,int> mp;
        for (int i=0; i<position.size(); i++){
            mp.emplace( make_pair(position[i],speed[i]) );
        }

        stack <float> st;
        for(auto i:mp){
            
            float t=float(target-i.first)/float(i.second);
            cout<<t<<" ";
            st.emplace(t);
        }

        int i=0;
        while(!st.empty()){
            float a=st.top();
            st.pop();

            while(!st.empty() && st.top()<=a){
                st.pop();
            }
            i++;
        }

        return i;
    }
};