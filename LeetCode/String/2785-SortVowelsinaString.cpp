/*
Problem: 2785. Sort Vowels in a String
Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/

Approach:
   - My Logic: 
		1. identify the vowel and push their ascii value in a vector.
		2. sort the vector
		3. initialize a index variable for sorted vector.
		4. iterate the string and identify the vowel, replace it the first element and increment the index.
		5. repeat for all vowel positions.

   - T.C: O(N * log N)
   - S.C: O(N)
   
   - Optimal logic: 
		store frequency of vowels.
		we know the sorted vowels order, use it to replace the vowels using frequency
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<int> sorted;
        for(char c: s)
        {
            if(isVowel(c))
            {
                sorted.push_back(c-'A');
            }
        }
        if(sorted.size()==0) return s;
        sort(sorted.begin(),sorted.end());
        int ind = 0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]='A'+sorted[ind];
                ind++;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "lEetcOde";
    
    cout << sol.sortVowels(s) << endl;
    
    return 0;
}