class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &i: tasks) freq[i-'A']++;

        auto itr=max_element(freq.begin(),freq.end());
        int maxi= *itr,s=tasks.size(),idleSpots=maxi-1,idleSpace=idleSpots*n;
        *itr=0;

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                idleSpace-=min(idleSpots,freq[i]);
                if(idleSpace<=0) return s;
            }
        }
        return s+idleSpace;
    }
};