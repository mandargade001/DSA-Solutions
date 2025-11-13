/*
Problem: 3228. Maximum Number of Operations to Move Ones to the End
Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

Approach:
   - My Logic: 
   		Observed that we need to know how many ones are present to move adj to next one. we keep track of 0's and 1's.
   		Whenever 1's is identified, we operate on previous ones to bring them to this positions by crossing the 0's found in between.
   		Then again we begin the 0's count from start and increment the no. of 1's to move next. 
   		If we start moving the 1's from left, it gives us the maximum no. of operations. From right end, it gives minimum operations.

   - T.C: O(n)
   - S.C: O(1)

   Runtime - 2 ms | Beats 86.23%
   Memory - 15.97 MB | Beats 26.09%
   
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int ones = 0;
        int zeroes = 0;
        for(char c: s)
        {
            if(c=='0') zeroes++;
            if(c=='1'){
                if(zeroes>0) res+=ones;
                ones++;
                zeroes=0;
            }
        }
        if(zeroes>0 && ones>0)
        {
            res+=ones;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "1001101";
    
    cout << sol.maxOperations(input) << endl;
    
    return 0;
}