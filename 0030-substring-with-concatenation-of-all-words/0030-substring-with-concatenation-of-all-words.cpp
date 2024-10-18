class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> ans;

        for(auto &i: words) map[i]++;
        int len=words[0].size(),n=s.size();

        for(int i=0;i<len;i++){
            unordered_map<string, int> seen;
            int windowSize=0;
            for(int j=i; j+len<=n;j+=len){
                
                string sub=s.substr(j,len);
                auto itr=map.find(sub);

                if(itr==map.end()){
                    seen.clear();
                    windowSize=0;
                }
                else{
                    seen[sub]++;
                    windowSize++;

                    while( windowSize > words.size() ||  seen[sub]>itr->second ){
                        string prev=s.substr(j-(windowSize-1)*len ,len);
                        seen[prev]--;
                        windowSize--;
                    }
                    if(windowSize==words.size()) ans.emplace_back(j-(windowSize-1)*len);
                }

            }
        }
        return ans;
    }
};