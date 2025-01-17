class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> ump;

        for(auto &i: time) ump[i%60]++;
        int ans=0;
        for(auto &i: ump){
            int num=i.first,count=i.second;
            if(num==30 || num==0) ans+=count*(count-1);
            else if(ump.count(60-num))ans+=count*ump[60-num];
        }
        return ans/2;
    }
};