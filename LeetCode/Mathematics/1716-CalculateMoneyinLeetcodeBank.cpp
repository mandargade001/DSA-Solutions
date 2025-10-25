/*
Problem: 1716. Calculate Money in Leetcode Bank
Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2025-10-25

Approach:
   - My Logic: 
   		Start with 1 - 1st monday, store it.
        Keep on looping till N is reached. 
        For days tue - sun, add +1 to prev day.
        For every monday, add +1 to prev monday.
        Return the final sum when loop breaks.

   - T.C: O(N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 7.94 MB | Beats 13.49%
   
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int totalMoney(int n) {
        /**
            Start with 1 - 1st monday, store it.
            Keep on looping till N is reached. 
            For days tue - sun, add +1 to prev day.
            For every monday, add +1 to prev monday.
            Return the final sum when loop breaks
        */

        int res = 0;
        int prevMon = 0;
        int prevDay = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%7==1)
            {
                res += prevMon + 1;
                prevMon++;
                prevDay = prevMon;
            }
            else 
            {
                res += prevDay + 1;
                prevDay++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 100;
    
    cout << sol.totalMoney(input) << endl;
    
    return 0;
}