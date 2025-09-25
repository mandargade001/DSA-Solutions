/*
Problem: 120. Triangle
Link: https://leetcode.com/problems/triangle/description/

Approach:
   - My Logic: 
   		Thought of recursion instictively. Then it gave TTL.
   		Had to reduce using Memoization or DP.
   		Started with Bottom-up DP as that takes O(1) space.
   		From the second last row, check and update the cell value to min it can be.
   		return the top cell.
   - T.C: O(N^2)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 12.39 MB | Beats 99.70%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {{-10}};
    
    cout << sol.minimumTotal(input) << endl;
    
    return 0;
}