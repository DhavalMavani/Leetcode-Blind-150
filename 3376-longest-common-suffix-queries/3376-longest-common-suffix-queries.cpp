
class Trie {
public:
    Trie* child[26] = {nullptr};
    vector<int> index;
    ~Trie() { 
        for (int i = 0; i < 26; ++i) 
            delete child[i]; 
    }
};

class Solution {
public:
    void add(Trie* head, int& index, const string& word) {
        Trie* curr = head;
        int n = word.size();
        for (int i = n - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (curr->child[c] == NULL) {
                Trie* temp = new Trie();
                curr->child[c] = temp;
            }
            curr = curr->child[c];
            curr->index.emplace_back(index);
        }
    }

    int lcsIndex(Trie* head, const string& word, const vector<string>& wordsContainer) {
        int l = word.size();
        Trie* curr = head;
        for (int i = l - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (curr->child[c] == nullptr) break;
            curr = curr->child[c];
        }
        int currLen = INT_MAX, ans = -1;
        int indSize = curr->index.size();
        for (int i = indSize - 1; i >= 0; i--) {
            int temp = curr->index[i];
            if (wordsContainer[temp].size() <= currLen) {
                currLen = wordsContainer[temp].size();
                ans = temp;
            }
        }
        return ans;
    }

    vector<int> stringIndices(const vector<string>& wordsContainer, const vector<string>& wordsQuery) {
        vector<int> ans;
        int n = wordsContainer.size(), minLen = INT_MAX, minInd = 0;
        Trie* containerTrie = new Trie();

        for (int i = 0; i < n; i++) {
            if (wordsContainer[i].size() < minLen) {
                minLen = wordsContainer[i].size();
                minInd = i;
            }

            add(containerTrie, i, wordsContainer[i]);
        }

        for (const auto& i : wordsQuery) {
            int lcsInd = lcsIndex(containerTrie, i, wordsContainer);
            if (lcsInd == -1) ans.emplace_back(minInd); 
            else ans.emplace_back(lcsInd);
        }
        return ans;
    }
};