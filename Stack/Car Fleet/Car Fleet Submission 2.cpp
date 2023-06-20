class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,int> > v1;
        for (int i=0; i<position.size(); i++){
            v1.emplace_back( make_pair(position[i],speed[i]) );
        }
        sort(v1.begin(),v1.end(), greater<pair<int,int>>() );

        int i=0,ans=0;
        while(i<v1.size()){

            float t=float(target-v1[i].first)/float(v1[i].second);
            cout<<t<<" ";
            i++;
            while(i<v1.size() && float(target-v1[i].first)/float(v1[i].second)<=t){
                i++;
            }
            ans++;            
        }
        return ans;
    }
};