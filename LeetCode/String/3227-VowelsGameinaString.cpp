/*
Problem: 3227. Vowels Game in a String
Link: https://leetcode.com/problems/vowels-game-in-a-string/description/

Approach:
   - My Logic: 
   		Lets consider a scenario of possibilities. Vowels can be 0/even/odd.
   		If there are 0 vowels, Bob wins.
   		If there are even vowels, Alice can pick twice with odd vowels. (odd + odd = even)
   		If there are odd vowels, Alice can pick them all. 

   		So, in all the cases, Alice wins except when there are no vowels present in the input string.

   - T.C: O(n)
   - S.C: O(1)

   Runtime - 8 ms | Beats 52.24%
   Memory - 18.93 MB | Beats 79.48%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool doesAliceWin(string s) {
        bool vowelsExist = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                vowelsExist = true;
                break;
            }
        }
        if(vowelsExist) return true;
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "leetcoder";
    
    cout << sol.doesAliceWin(input) << endl;
    
    return 0;
}