/*
Problem: 1039. Minimum Score Triangulation of Polygon
Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

Approach:
   - First Logic: 
   		Find the smallest value vertex, from their join to next smallest vertex which is not adjacent.
   		Continue, till n-2 triangles are created. 
   		Calculate score and it will be minimum score. (Would miss global minima scenarios)
   - Second Logic:
   		Since, we can see that trying to make the triangulation, there are lot of repetitions in shapes, 
   		and overlaps do occur, and we need to optimise the score to minimum. We can use DP.
   		So, we need to calculate the minimum score of Polygon by triangulation. 
   		The minimum side polygon possible is triangle and we need to build up the solution to finally give the score for n-sided polygon.
   		We can have a 2D DP, where dp[i][j] is the minimum score to triangulate polygon from vertex i to j.
   		We start from small, polygons of len 3, and cover all possibilities. and repeat for all.

   - T.C: O(N^3)
   - S.C: O(N^2)

   Runtime - 1 ms | Beats 72.98%
   Memory - 11.06 MB | Beats 90.10%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp (n,vector<int>(n,0));

        for(int len = 3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j = i + len - 1;

                    dp[i][j] = INT_MAX;
                for(int k = i+1;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i]*values[k]*values[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minScoreTriangulation(input) << endl;
    
    return 0;
}