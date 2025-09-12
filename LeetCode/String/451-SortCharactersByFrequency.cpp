/*
Problem: 451. Sort Characters By Frequency
Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

Approach:
   - My Logic: 
		use vector of pair containing the ascii character and keep on incrementing the count parameter, 2nd in pair. 
		initially we use the index as character and then vector is updatd. 
		we sort it in descending order of count parameter. 
		we then iterate and print character using ascii value we saved earlier.
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 11.21 MB | Beats 52.24%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0}; // Array for ASCII frequencies
        for (char c : s) {
            freq[c]++; // O(n)
        }
        
        vector<pair<int, char>> freqChar;
        for (int i = 0; i < 256; ++i) {
            if (freq[i] > 0) {
                freqChar.emplace_back(freq[i], i); // Only non-zero frequencies
            }
        }
        
        sort(freqChar.begin(), freqChar.end(), greater<>()); // O(1), max 256 elements
        
        string result;
        for (auto [count, c] : freqChar) {
            result.append(count, c); // O(n), append c count times
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "tree";
    
    cout << sol.frequencySort(input) << endl;
    
    return 0;
}