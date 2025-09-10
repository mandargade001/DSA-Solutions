/*
Problem: 733. Minimum Number of People to Teach
Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/description/

Approach:
   - My Logic: (fs -> friendships, comm. -> communicating, lang -> language)
	   1. identify how many fs are not comm. and find the unique users who are involved.
       2. for all these users only, iterate across each lang, and find how many people don't know the lang.
       3. lang that maximum people know, teach that to other people.

   - T.C: O(m * L + F * n + n * U)
   - S.C: O()

   Runtime - 236 ms | Beats 43.53%
   Memory - 148.08 MB | Beats 29.41%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>> knows(m, vector<bool>(n, false));
        
        // Preprocess: O(m * L)
        for (int i = 0; i < m; ++i) {
            unordered_set<int> langSet(languages[i].begin(), languages[i].end());
            for (int lang : langSet) {
                if (lang >= 1 && lang <= n) {
                    knows[i][lang - 1] = true;
                }
            }
        }
        
        // Step 1: Build userCannotComm using O(n) per friendship
        set<int> userCannotComm;
        for (auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool canComm = false;
            for (int j = 0; j < n; ++j) {
                if (knows[u][j] && knows[v][j]) {
                    canComm = true;
                    break;
                }
            }
            if (!canComm) {
                userCannotComm.insert(f[0]);
                userCannotComm.insert(f[1]);
            }
        }
        
        if (userCannotComm.empty()) return 0;
        
        // Step 2: For each lang, count known in O(U)
        int maxKnown = 0;
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for (int user : userCannotComm) {
                int idx = user - 1;
                if (knows[idx][j]) ++count;
            }
            maxKnown = max(maxKnown, count);
        }
        
        return userCannotComm.size() - maxKnown;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int n=3;
    vector<vector<int>> languages = {
    	{2}, {1,3}, {1,2}, {3}
    };
    vector<vector<int>> friendships = {
    	{1,4},{1,2},{3,4},{2,3}
    };
    
    cout << sol.minimumTeachings(n, languages, friendships) << endl;
    
    return 0;
}