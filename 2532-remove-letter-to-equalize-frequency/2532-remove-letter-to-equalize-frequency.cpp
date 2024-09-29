class Solution {
public:
    bool equalFrequency(string word) {
        if(word.size()<=3) return true;

        vector<int> chars(26,0);
        for(auto &i: word) chars[i-'a']++;

        for(int i=0;i<26;i++){
            if(chars[i]!=0){
                chars[i]--;
                int f=max(chars[word[0]-'a'],chars[word[1]-'a']);
                bool isPossible=true;
                for(int j=0;j<26;j++){
                    if(chars[j]!=0 && chars[j]!=f){
                        isPossible=false;
                        break;
                    }
                }
                if(isPossible) return true;
                
                chars[i]++;
            }
        }

        return false;
    }
};