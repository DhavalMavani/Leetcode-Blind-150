class Solution {
public:

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        unordered_map<int, vector<int>> bucket;
        int min_atk = INT_MAX;
        int max_atk = INT_MIN;

        // Group the defense values by attack values and find min and max attack values
        for (const auto &prop : properties) {
            int attack = prop[0], defense = prop[1];
            bucket[attack].push_back(defense);
            min_atk = min(min_atk, attack);
            max_atk = max(max_atk, attack);
        }

        int count = 0;
        int max_def = -1;

        // Iterate from max attack to min attack
        for (int i = max_atk; i >= min_atk; --i) {
            if (bucket.find(i) == bucket.end()) continue;

            // Count the number of properties with defense less than max_def
            for (int defense : bucket[i]) {
                if (defense < max_def) {
                    count++;
                }
            }

            // Update max_def with the maximum defense value in the current bucket
            max_def = max(max_def, *max_element(bucket[i].begin(), bucket[i].end()));
        }

        return count;
    }
};