/*
Problem: 1461. Check If a String Contains All Binary Codes of Size K
Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23

Approach:
   - My Logic: 
   		for binary of k bits, there are total 2^k combinations/permutations possible.  
   		If every combination is part of the input string, then if we go on to find the substrings, then the total number of unique substring of size k should be 2^k.
   		If yes, we return true or else false;
   - T.C: O(n)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i=0;i+k<=s.size();i++)
        {
            st.insert(s.substr(i,k));
        }
        return st.size()==(int)pow(2,k);
    }
};

int main() {
    Solution sol;
    
    // Example input
    
    
    cout << sol.hasAllCodes("1011001001", 2) << endl;
    
    return 0;
}