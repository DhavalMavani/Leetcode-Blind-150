class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> result;

        int length = words[0].size();

        for (string &word: words) map[word]++;

        // Iterate for each offset (As many times as the number of characters in each word)
        for (int offset = 0; offset < length; offset++) {
            int size = 0; // Sliding window size.
            
            unordered_map<string, int> seen; // Sliding window memory.

            // Iterate over the string, with the step equals to length.
            for (int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                string sub = s.substr(i, length);

                // If the word is absent in the reference map, we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences of the word in seen map.
                seen[sub]++;
                size++;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window, shrinking it from the left.
                    seen[first]--;
                    size--;
                }
                
                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size()) result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};