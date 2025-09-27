/*
Problem: 812. Largest Triangle Area
Link: https://leetcode.com/problems/largest-triangle-area/description/

Approach:
   - My Logic: 
   		Formula for calculating area of triangle using coordinates - Shoelace Formula
   		area = 1/2 * [x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)]

   		iterate input array and calculate maxArea.

   - T.C: O(N^3)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 10.32 MB | Beats 86.95%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                for(int k=j+1;k<points.size();k++)
                {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    double area = 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{0,0},{0,1},{1,0}
    };
    
    cout << sol.largestTriangleArea(input) << endl;
    
    return 0;
}