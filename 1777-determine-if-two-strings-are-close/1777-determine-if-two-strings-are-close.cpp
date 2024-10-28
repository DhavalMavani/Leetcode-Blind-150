class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size(),n2=word2.size();
        if(n!=n2) return false;
        
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0;i<n;i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(freq1[i]==0 && freq2[i]!=0) return false;
        sort(freq1.begin(),freq1.end(),greater());
        sort(freq2.begin(),freq2.end(),greater());


        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
            else if(!freq1[i]) return true;
        }

        return true;
    }
};