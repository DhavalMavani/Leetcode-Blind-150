class Solution {
public:
    string end,begin;
    vector<vector<string>> ans;
    void dfs(unordered_map<string,vector<string>> &ump, string node, vector<string> path){
        path.emplace_back(node);
        for(auto i: ump[node]) dfs(ump,i,path);
        
        if(node==begin){
            reverse(path.begin(),path.end());
            ans.emplace_back(path);
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        end=endWord;
        begin=beginWord;
        unordered_map<string,int> dict;
        for (int i = 0; i < wordList.size(); i++) dict.insert({wordList[i],-1});
        
        if(!dict.count(endWord)) return {};

        unordered_map<string,vector<string>> ump;

        queue<string> q;
        q.emplace(beginWord);
        bool reachable=false;
        int level = 1;
        while (!q.empty() && !reachable) {
            int count = q.size();
            unordered_set<string> visitedThisLevel;
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                if(visitedThisLevel.count(word)) continue;
                visitedThisLevel.emplace(word);
                
                if (word == endWord){
                    reachable=true;
                    break;
                }

                dict[word]=level;
                for (int j = 0; j < word.size(); j++) {
                    string wordCopy=word;
                    for (int k = 0; k < 26; k++) {
                        wordCopy[j] = k + 'a';
                        if (dict.count(wordCopy) && ( dict[wordCopy]==-1 ||  dict[wordCopy]==level+1)  ) {
                            q.push(wordCopy);
                            dict[wordCopy]=level+1;
                            ump[wordCopy].emplace_back(word);
                        }
                    }
                }
            }
            level++;
        }

        for(auto i: dict){
            cout<<"("<<i.first<<" -> "<<i.second<<") ";
        }
            cout<<endl;
        for(auto i: ump){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }


        if(reachable) dfs(ump,endWord,{});
        return ans;
    }

};
