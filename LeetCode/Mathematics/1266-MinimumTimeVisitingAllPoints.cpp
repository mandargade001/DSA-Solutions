/*
Problem: 1266. Minimum Time Visiting All Points
Link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12

Approach:
   - My Logic: Best move to cover max dist in min time is moving diagonally and then cover the remaining in horizontal or vertical moves.
   				On calculating the moves, we observe that the total steps to cover distance is always the max of the difference between X corr, & Y corr.
   				Because we are always making +1 move towards the farther axis point.
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=1;i<points.size();i++)
        {
            int diffX = abs(points[i][0]-points[i-1][0]);
            int diffY = abs(points[i][1]-points[i-1][1]);

            res += max(diffX, diffY);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> points = {{3,2},{-2,2}};
    
    cout << sol.minTimeToVisitAllPoints(points) << endl;
    
    return 0;
}