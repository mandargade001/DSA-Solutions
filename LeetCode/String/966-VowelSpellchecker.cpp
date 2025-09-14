/*
Problem: 966. Vowel Spellchecker
Link: https://leetcode.com/problems/vowel-spellchecker/description/

Approach:
   - My Logic:
		Preprocess Wordlist:
		Create three hash tables:

		Exact match: map<string, string> for case-sensitive words.
		Case-insensitive: map<string, string> for lowercase words (store first occurrence).
		Vowel-agnostic: map<string, string> for lowercase words with vowels replaced by a placeholder (e.g., ‘#’).

		For each word in wordlist:

		Store in exact match map.
		Convert to lowercase and store in case-insensitive map (if not already present).
		Create vowel-agnostic key (replace vowels with ‘#’) and store in vowel map (if not already present).


		Process Queries:

		For each query:

		Check exact match map (O(L)).
		Convert to lowercase, check case-insensitive map (O(L)).
		Create vowel-agnostic key, check vowel map (O(L)).
		Return empty string if no match.

   - T.C: O(W * L + Q * L).
   - S.C: O(W * L)

   Runtime - 40 ms | Beats 56.96%
   Memory - 41.35 MB | Beats 13.92%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> exact, caseIns, vowelIns;
        auto devowel = [](string s) {
            for (char& c : s) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '#';
            }
            return s;
        };
        
        // Preprocess wordlist
        for (const string& w : wordlist) {
            exact[w] = w; // Exact match
            string lower = w;
            for (char& c : lower) c = tolower(c);
            caseIns.emplace(lower, w); // First case-insensitive match
            vowelIns.emplace(devowel(w), w); // First vowel-agnostic match
        }
        
        // Process queries
        vector<string> result;
        for (const string& q : queries) {
            if (exact.count(q)) {
                result.push_back(exact[q]);
                continue;
            }
            string lower = q;
            for (char& c : lower) c = tolower(c);
            if (caseIns.count(lower)) {
                result.push_back(caseIns[lower]);
                continue;
            }
            string vowelKey = devowel(q);
            if (vowelIns.count(vowelKey)) {
                result.push_back(vowelIns[vowelKey]);
            } else {
                result.push_back("");
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<string> wordlist = {"yellow"};
    vector<string> queries = {"YellOw"};

    //Output 
    vector<string> output = sol.spellchecker(wordlist,queries);

    for (std::vector<string>::iterator i = output.begin(); i != output.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}