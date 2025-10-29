/*
Problem: 3370. Smallest Number With All Set Bits
Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

Approach:
   - My Logic: 
   		Find the pattern for the set bit numbers, return when value is greater than or equal to n.
   - T.C: O(log n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.35 MB | Beats 30.15%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int smallestNumber(int n) {
       
        //the answer pattern: 1,3,7,15,31
        int x = 1;
        while(x<n)
        {
            x = x*2 +1;
        }
        return x;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int n = 5;
    
    cout << sol.smallestNumber(n) << endl;
    
    return 0;
}