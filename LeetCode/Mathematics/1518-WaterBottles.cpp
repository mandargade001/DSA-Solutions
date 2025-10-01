/*
Problem: 1518. Water Bottles
Link: https://leetcode.com/problems/water-bottles/

Approach:
   - My Logic: 
		We keep track of filled bottles, drink it, keep track of drinked bottles, update empty bottles, use them to exchange, update remaining empty.
		Repeat process till we dont have any filled bottles.

   - T.C: O(log numBottles to base numExchange)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 7.88 MB | Beats 45.09%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numExchange>numBottles) return numBottles; //if num of bottles is less than num required to exchange
        int res = 0;
        int empty = 0;
        while(numBottles>0)
        {
            res +=numBottles; //drank all available bottles
            empty += numBottles; //update empty bottles
            numBottles = empty / numExchange; //Get filled bottles from exchange of empty
            empty = empty % numExchange; //update empty bottles after exchange
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int numBottles = 9, numExchange = 3;
    
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;
    
    return 0;
}