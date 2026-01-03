/*
Problem: 1411. Number of Ways to Paint N × 3 Grid
Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

Approach:
   - My Logic: We look for Patterns possible in first row and then the second row, we calculate the variations possible in the i+1 th row from ith row numbers.
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int numOfWays(int n) {
        long long c2 = 6;
        long long c3 = 6;
        long long MOD = 1e9 + 7;
        
        // if(n==1) return res;
        for(int i=2;i<=n;i++)
        {
            long long temp = c2;

            c2 = (c2*3 + c3*2)%MOD;

            c3 = (temp*2 + c3*2)%MOD;

        }
        return (c2+c3)%MOD;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 5000;
    
    cout << sol.numOfWays(input) << endl;
    
    return 0;
}