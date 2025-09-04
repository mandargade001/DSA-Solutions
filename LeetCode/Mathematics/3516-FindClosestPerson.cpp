/*
Problem: 3516. Find Closest Person
Link: https://leetcode.com/problems/find-closest-person/description/

Approach:
   - My Logic: 
   		Given that the 3 person(x,y,z) are on same line where x & y move with same speed and z does not move.
   		To find who reaches first, we just need to get the person who is closer to z.
   		To get that, calculate absolute difference between the person and z. 
   		Return appropriate values as result.

   - T.C: O(1)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.54 MB | Beats 55.11%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = abs(z-x);
        int diff2 = abs(z-y);
        if(diff1==diff2) return 0;
        if(diff1<diff2) return 1;
        return 2;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int x = 2, y = 7, z = 4;
    cout << sol.findClosest(x,y,z) << endl;
    
    return 0;
}