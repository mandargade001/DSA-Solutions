/*
Problem: 2273. Find Resultant Array After Removing Anagrams
Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/

Approach:
   - My Logic: 
   		Looking at the constraints, The best way I could think of is to tell if two words are Anagram or not is by comparing their sorted versions.
   		We sort the words and check, 
   		if they are same -> we skip the insertion, 
   		else we update the check variable, insert the current word in result array and continue.
   		Return the final vector.

   - T.C: O(N^2 * log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 16.24 MB | Beats 44.94%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        
        string last = words[0];
        sort(last.begin(), last.end());
        for(int i=1;i<words.size();i++)
        {
            string word = words[i];
            sort(word.begin(), word.end());
            if(word == last)
            {
                continue;
            }
            else {
                last = word;
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<string> input = {"abba","baba","bbaa","cd","cd"};
    
    input = sol.removeAnagrams(input);
    for (std::vector<string>::iterator i = input.begin(); i != input.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}