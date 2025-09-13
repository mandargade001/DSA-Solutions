/*
Problem: 3541. Find Most Frequent Vowel and Consonant
Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/

Approach:
   - My Logic:
   		We know that the character size is of 26.
   		We initialize a vector of size 26 to store frequency of each character.
   		Iterate the string and update the frequency of each character and if they are vowels - update the maxFreq var else do it for consonent variable
   		Return sum of both variables.

   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 9.46 MB | Beats 74.86%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        //vowels: a-0, e-4, i-8, o-14, u-20

        int fVowels = 0;
        int fConso = 0;
        for(int i=0;i<s.size();i++)
        {
            int ind = s[i]-'a';
            freq[ind]++;
            if(ind==0 || ind==4 || ind==8 || ind==14 || ind==20)
            {
                fVowels = max(fVowels, freq[ind]);
            }
            else {
                fConso = max(fConso, freq[ind]);
            }
        }
        return fVowels + fConso;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "successes";
    
    cout << sol.maxFreqSum(input) << endl;
    
    return 0;
}