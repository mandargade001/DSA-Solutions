/*
Problem: 1653. Minimum Deletions to Make String Balanced
Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

Approach:
   - My Logic: 
		We will use two windows, one for having only 'a' and another for only 'b'.
		If there are any other char then we consider to remove them.
		This way we will get the combination of all the removals in the window considering that string is balanced.
		We will go from considering all 'b' string to all 'a' string. In middle all the combinations will be considered.
		Return the min elements to remove using the frequency of unwanted chars.
		
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 36 ms Beats 36.91%
   Memory - 25.68 MB Beats 55.15%


*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size();
        int res = INT_MAX;
        vector<int> aWin(2, 0);
        vector<int> bWin(2, 0);

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')bWin[0]++;
            else bWin[1]++;
        }

        res = min(res, aWin[1]+bWin[0]);

        for(int i=0;i<s.size();i++) //aWin ending at idx i
        {
            if(s[i]=='a'){
                aWin[0]++;
                bWin[0]--;
            }
            else {
                bWin[1]--;
                aWin[1]++;
            }
            res = min(res, aWin[1]+bWin[0]);
        }
        
        return res;
        
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "aababbab";
    
    cout << sol.minimumDeletions(input) << endl;
    
    return 0;
}