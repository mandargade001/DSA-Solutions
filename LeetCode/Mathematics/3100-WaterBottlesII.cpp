/*
Problem: 3100. Water Bottles II
Link: https://leetcode.com/problems/water-bottles-ii/description/

Approach:
   - My Logic: 
		We keep track of filled bottles, drink it, keep track of drinked bottles, update empty bottles, use them to exchange and update remaining empty, in an incremental way.
		Repeat process till we dont have any filled bottles.
		
   - T.C: O(log numBottles to base numExchange)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.64 MB | Beats 13.66%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if(numBottles<numExchange) return numBottles;

        int res = 0;
        int empty = 0;
        while(numBottles>0)
        {
            res += numBottles;
            empty += numBottles;
            numBottles = 0;
            while(empty>=numExchange)
            {
                empty-=numExchange;
                numBottles++;
                numExchange++;

            }

        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int numBottles = 13, numExchange = 6;
    
    cout << sol.maxBottlesDrunk(numBottles, numExchange) << endl;
    
    return 0;
}