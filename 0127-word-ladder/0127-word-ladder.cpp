class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map <string, unordered_set<string>> ump;
        int wordsize=beginWord.size();
        for(auto &word: wordList){
            for(int i=0;i<wordsize;i++){
                string temp=word;
                temp[i]= '*';
                ump[temp].emplace(word);
            }
        }
        queue <string> q1;
        unordered_map <string,int> hasVisited;
        q1.emplace(beginWord);
        int ctr=0;
        while( !q1.empty() ){
            int n=q1.size();
            ctr++;
            for(int i=0;i<n;i++){
                for(int i=0;i<wordsize;i++){
                    if(q1.front()==endWord){
                        return ctr;
                    }
                    string t1=q1.front();
                    t1[i]='*';
                    for(auto word: ump[t1]){
                        if(hasVisited[word]==1){
                            continue;
                        }
                        q1.emplace(word);
                        hasVisited[word]=1;
                    }
                }
                q1.pop();
            }
        }
        return 0;
    }
};