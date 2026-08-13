#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        
        // set stores intervals: [start, end] of identical repeating characters
        set<pair<int, int>> intervals;
        multiset<int> lengths;

        auto add_interval = [&](int start, int end) {
            intervals.insert({start, end});
            lengths.insert(end - start + 1);
        };

        auto remove_interval = [&](auto it) {
            lengths.erase(lengths.find(it->second - it->first + 1));
            intervals.erase(it);
        };

        // Initialize intervals
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            add_interval(i, j - 1);
            i = j;
        }

        vector<int> ans;
        int k = queryIndices.size();

        for (int q = 0; q < k; ++q) {
            int idx = queryIndices[q];
            char new_char = queryCharacters[q];

            if (s[idx] == new_char) {
                ans.push_back(*lengths.rbegin());
                continue;
            }

            // Find the interval containing `idx`
            auto it = intervals.upper_bound({idx, n});
            --it;
            int start = it->first;
            int end = it->second;

            remove_interval(it);

            // Split or shrink the current interval
            if (start < idx) {
                add_interval(start, idx - 1);
            }
            if (idx < end) {
                add_interval(idx + 1, end);
            }

            // Add the new single-character interval at `idx`
            s[idx] = new_char;
            add_interval(idx, idx);

            // Merge with the left neighbor if characters match
            auto curr = intervals.find({idx, idx});
            if (curr != intervals.begin() && s[prev(curr)->second] == new_char) {
                auto left_it = prev(curr);
                int l_start = left_it->first;
                int r_end = curr->second;
                remove_interval(left_it);
                remove_interval(intervals.find({idx, idx}));
                add_interval(l_start, r_end);
            }

            // Re-find the current interval containing `idx` for right check
            curr = intervals.upper_bound({idx, n});
            --curr;
            auto next_it = next(curr);
            if (next_it != intervals.end() && s[next_it->first] == new_char) {
                int l_start = curr->first;
                int r_end = next_it->second;
                remove_interval(curr);
                remove_interval(next_it);
                add_interval(l_start, r_end);
            }

            // The maximum repeating length is the largest element in multiset
            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};
